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
	}
	closedir(pDir);
	return buff.size();
}

int Init(vector<m_buffer> &buff, unsigned char**Txt, int *sizeArray)
{
	int size = buff.size();
	for (int i = 0; i < size; i++)
	{
		Txt[i] = buff[i].pBuff;
		sizeArray[i] = buff[i].size;
	}
	return 0;
}
