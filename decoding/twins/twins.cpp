#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <zlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>
#include <ctime>
#include <math.h>
#include <sys/time.h>
#include <vector>
#define SIZE_CHUNK (8 * 1024)
#define MAX_SRC_FILE_SIZE (10 * 1024 * 1024)
unsigned char *pSrcs[900];
long int FileSize[900];
unsigned char *pDsts[900];
int count;
double Time = 0;
clock_t startTime, endTime;
clock_t spend;
void freememory(int start, int end, unsigned char *p[])
{
    for (int i = start; i <= end; i++)
    {
        free(p[i]);
        p[i] = NULL;
    }
    return;
}

int getFileName(char *dirPath)
{
    DIR *dir = opendir(dirPath);
    if (dir == NULL)
    {
        printf("%s\n", strerror(errno));
        return -1;
    }
    chdir(dirPath);
    char t[] = "/";
    strcat(dirPath, t);
    struct dirent *ent;
    count = 0;
    while ((ent = readdir(dir)) != NULL)
    {
        char str[50];
        snprintf(str, sizeof(str), "%s", dirPath);
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
        {
            continue;
        }
        strcat(str, ent->d_name);
        FILE *pfile = NULL;
        pfile = fopen(str, "rb");
        if (pfile == NULL)
        {
            return -1;
        }
        fseek(pfile, 0, SEEK_END);
        int file_length = ftell(pfile);
        rewind(pfile);

        // allocate memory for compressed data
        int buf_length = file_length * sizeof(unsigned char);
        unsigned char *fbuf = (unsigned char *)malloc(buf_length);
        memset(fbuf, 0, buf_length);
        // fill content to memory
        int read_length = fread(fbuf, sizeof(unsigned char), file_length, pfile);
        if (read_length != file_length)
        {
            exit(0);
        }

        pSrcs[count] = fbuf;
        FileSize[count] = buf_length;
        long unsigned int dstLength = MAX_SRC_FILE_SIZE * sizeof(unsigned char);
        unsigned char *desbuf = (unsigned char *)malloc(dstLength);
        memset(desbuf, 0, dstLength);
        pDsts[count] = desbuf;
        count++;
    }
    closedir(dir);
    return 1;
}

typedef struct _M
{
    unsigned char *pBuf;
    int size;
} m_buffer;

int LoadText(const char *path, std::vector<m_buffer> &buff)
{
    int len = 0;
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
		buff.push_back({pBuf, static_cast<int>(statbuf.st_size)});
    }
    closedir(pDir);
    return len;
}

#define SIZE 1024*1024*300*4
int file_inflate(const char *fsrc)
{
    std::vector<m_buffer> buff;
    LoadText(fsrc,buff);

    struct timeval tv;
    gettimeofday(&tv, NULL);
    startTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    uLongf distlen;
    unsigned char *out = new unsigned char[SIZE];
    memset(out,0,SIZE);
    gettimeofday(&tv, NULL);
    startTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    for (int i = 0; i < buff.size(); i++)
    {
        int size = buff[i].size;
        unsigned char *pFile = buff[i].pBuf;
        
        distlen = 2*SIZE;
        int res = uncompress(out, &distlen, pFile, size);
        if(res != 0){
            printf("error!\n");
            break;
        }
    }
    gettimeofday(&tv, NULL);
    endTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    spend += endTime - startTime;
    free(out);
    printf("decoding time is %d\n", spend);
    return 1;
}
int main(int argc, char *argv[])
{
    file_inflate(argv[1]);
    return 0;
}
