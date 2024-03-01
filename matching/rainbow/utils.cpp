#include "utils.h"
#include "dictionary.h"
#include <sys/time.h>
#include <dirent.h>
#define sSIZE 32000000

extern unsigned long g_scan;
extern clock_t spend;
extern unsigned int g_match;
extern unsigned long long compress;
extern unsigned long long total;
extern int g_index;
extern int literal_num;
extern int maxLen;

void GetDictionaryState(short *DictionaryState, FSM *fsm)
{
	const unsigned char *byte = kBrotliDictionaryData;
	short state = 0;
	for (int i = 0; i < DICTIONARY_BYTES; i++)
	{
		state = fsm->list[state * 256 + *byte];
		*DictionaryState = state;
		byte++;
		DictionaryState++;
	}
}

void Performance()
{
	printf("time:%d ms, matched:%d, scan:%d, total:%d, skip-ratio: %.2f%, throughput %.2f mbps,literal-num:%d, pointer-ratio:%.2f\n",
		   spend, g_match, g_scan, total, 100 * (1.0 - (g_scan * 1.0 / total)), (compress * 8) / (double)(spend) / 1000, literal_num, 100 * (1.0 - (literal_num * 1.0 / total)));
}

int readFileName(char *path,vector<string> &name)
{
	struct stat statbuf;
	string szDir = "";
	szDir += path;
	DIR *pDir = opendir(szDir.c_str());
	struct dirent *entry;
	while ((entry = readdir(pDir)) != NULL)
	{
		string s = szDir;
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		s += entry->d_name;
		name.push_back(s);
	}
	closedir(pDir);
	return 0;
}

int LoadText(char *path, vector<m_buffer> &buff, vector<string> &name)
{
	struct stat statbuf;
	char szDir[256] = {0};
	strcpy(szDir, path);
	DIR *pDir = opendir(szDir);
	struct dirent *entry;
	char szFile[256];
	while ((entry = readdir(pDir)) != NULL)
	{
		if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		sprintf(szFile, "%s/%s", szDir, entry->d_name);
		unsigned long dwRead = 0;
		stat(szFile, &statbuf);
		unsigned char *pBuf = (unsigned char *)malloc(statbuf.st_size);
		FILE *hFile = fopen(szFile, "rb");
		if (hFile == NULL)
		{
			printf("open file %s error\n", entry->d_name);
			continue;
		}
		fread(pBuf, statbuf.st_size, 1, hFile);
		fclose(hFile);
		buff.push_back({pBuf, static_cast<size_t>(statbuf.st_size)});
	}
	closedir(pDir);
	return buff.size();
}

short SkipStaticPointer(unsigned char* dictionary, int length, int index, FSM* fsm, short state, short* stateArray,int position)
{
	short* refer = stateArray + index - 1;
	short* cur = stateArray + DICTIONARY_BYTES + position;
	for (int pos = 0; pos < length; pos++, refer++, cur++)
	{
		if (state == *refer)
		{
			memcpy(cur, refer + 1, sizeof(short) * (length - pos));
#ifdef ACTION
			for (int i = 0; i < length - pos; i++) {
				if (fsm->accept[cur[i]] == true) g_match++;
			}
#endif
			return cur[length - pos - 1];
		}
		else
		{
			*cur = ScanByte(state, dictionary[index++], fsm);
#ifdef ACTION
			 if (fsm->accept[state] == true) g_match++;
#endif
			g_scan++;
		}
	}
	return state;
}

short SkipDynamicPointer(unsigned char* contents, int length, int index, FSM* fsm, short state, short* stateArray, int position)
{
	short* cur = stateArray + DICTIONARY_BYTES + position;
	short* refer = cur + index - 1;
	unsigned char* token = contents + position + index; //refer str
	for (int pos = 0; pos < length; pos++, refer++, cur++,token++)
	{
		if (state == *refer)
		{
			if (cur - refer >= length)
			{
				memcpy(cur, refer + 1, sizeof(short) * (length - pos));
			}
			else {
				for (int i = 0; i < length - pos; i++) {
					cur[i] = refer[i + 1];
				}
			}
#ifdef ACTION
			for (int i = 0; i < length - pos; i++) {
				if (fsm->accept[cur[i]] == true) g_match++;
			}
#endif
			return cur[length - pos - 1];
		}
		else
		{
			*cur = ScanByte(state, *token, fsm);
#ifdef ACTION
			if (fsm->accept[state] == true) g_match++;
#endif
			g_scan++;
		}
	}
	return state;
}
FSM *readFromFile(char *tableFile, char *acceptFile)
{
	vector<int> acceptVec;
	ifstream in_ac;
	in_ac.open(acceptFile);
	if (in_ac.is_open())
	{
		while (in_ac)
		{
			int temp_ac;
			in_ac >> temp_ac;
			acceptVec.push_back(temp_ac);
		}
		in_ac.close();
	}
	vector<int> vecTable;
	ifstream in_table;
	in_table.open(tableFile);
	if (in_table.is_open())
	{
		string line;
		while (!in_table.eof())
		{
			getline(in_table, line);
			if (in_table.fail())
				break;
			if (line.size() > 2)
			{
				stringstream stream(line);
				int count = 0;
				while (stream)
				{
					int temp_n;
					stream >> temp_n;
					if (count < 256)
					{
						vecTable.push_back(temp_n);
					}

					count++;
				}
			}
		}
	}
	int *list_ = new int[(int)vecTable.size()];
	bool *accept_ = new bool[(int)vecTable.size() / 256];
	for (int i = 0; i < (int)vecTable.size() / 256; i++)
	{
		accept_[i] = false;
	}
	for (int i = 0; i < vecTable.size(); i++)
	{
		list_[i] = vecTable[i];
	}
	for (auto it = acceptVec.begin(); it != acceptVec.end(); it++)
	{
		accept_[*it] = true;
	}
	FSM *fsm = new FSM;
	fsm->list = list_;
	fsm->accept = accept_;
	return fsm;
}