#include "utils.h"
#include "dictionary.h"
#include <sys/time.h>
#include <dirent.h>
#define sSIZE 3200000

extern unsigned long g_scan;
extern clock_t spend;
extern unsigned int g_match;
extern unsigned long long compress;
extern unsigned long long total;

extern int literal_num;


short naive_for_static(TokenInfo *token, int length, short *state_array, FSM *fsm, int state)
{

	for (int pos = 0; pos < length; pos++, token++, state_array++)
	{
		state = fsm->list[state * 256 + token->token];
		*state_array = state;
	}
	return state;
}

short naive_for_dynamic(TokenInfo *token, int length, short *state_array, FSM *fsm,int state){

	for (int pos = 0; pos < length; pos++, token++, state_array++)
	{
		state = fsm->list[state * 256 + token->token];
		*state_array = state;
	}
	return state;
}

/*void GetDictionaryState(short *DictionaryState, DFA *dfa)
{
	const unsigned char *byte = kBrotliDictionaryData;
	state_t start_state = 0;
	for (int i = 0; i < DICTIONARY_BYTES; i++)
	{
		state_t cur_state = dfa->get_next_state(start_state, *byte);
		*DictionaryState = cur_state;
		start_state = cur_state;
		byte++;
		DictionaryState++;
	}
}*/
void Performance()
{
	printf("time:%d ms, matched:%d, scan:%d, total:%d, skip-ratio: %.2f%, throughput %.2f mbps,literal-num:%d, pointer-ratio:%.2f\n",
		   spend, g_match, g_scan, total, 100 * (1.0 - (g_scan * 1.0 / total)), (compress * 8) / (double)(spend) / 1000, literal_num, 100 * (1.0 - (literal_num * 1.0 / total)));
}
extern int maxLen;
int LoadText(char *path, vector<m_buffer> &buff)
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
		FILE *hFile = fopen(szFile, "r");
		if (hFile == NULL)
		{
			printf("open file %s error\n", entry->d_name);
			continue;
		}
		fread(pBuf, statbuf.st_size, 1, hFile);
		fclose(hFile);
		buff.push_back({pBuf, static_cast<size_t>(statbuf.st_size)});
		if(statbuf.st_size > maxLen) maxLen = statbuf.st_size;
	}
	closedir(pDir);
	return buff.size();
}

int Init(vector<m_buffer> &buff, TokenInfo **Txt, int *sizeArray)
{
	int size = buff.size();
	for (int i = 0; i < size; i++)
	{
		Txt[i] = (TokenInfo *)buff[i].pBuff;
		sizeArray[i] = buff[i].size / sizeof(TokenInfo);
	}
	return 0;
}
