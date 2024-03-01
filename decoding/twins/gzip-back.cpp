#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <zlib.h>
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
#include <sys/time.h>
#define SIZE_CHUNK (8 * 1024)
#define MAX_SRC_FILE_SIZE (10 * 1024 * 1024)
unsigned char *pSrcs[900];
long int FileSize[900];
unsigned char *pDsts[900];
int count;
double Time = 0;
clock_t startTime, endTime;
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

int file_inflate(const char *fsrc)
{
    long unsigned int dstLength = MAX_SRC_FILE_SIZE * sizeof(unsigned char);
    long unsigned int tmpdstlength;
    int iRet = 0;

    struct timeval tv;
    gettimeofday(&tv, NULL);
    startTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    for (int i = 0; i < count; i++)
    {
        tmpdstlength = dstLength;
        iRet = 0;
        do
        {
            iRet = uncompress(pDsts[i], &tmpdstlength, pSrcs[i], FileSize[i]);
            if (0 == iRet)
            {
                break;
            }
            else if (-5 == iRet)
            {
                printf("error -5\n");
                return -1;
            }
            else
            {
                printf("error\n");
                return -1;
            }
        } while (1);
    }
    endTime = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    Time += endTime - startTime;
    printf("preprocess time is %d", Time);
    freememory(1, count, pSrcs);
    freememory(1, count, pDsts);
    return 1;
}
int main(int argc, char *argv[])
{
    int res = 0;

    if (argv[1])
    {
        res = getFileName(argv[1]);
    }
    if (res == -1)
    {
        printf("the directory is not exist!\n");
        return 0;
    }
    res = file_inflate(argv[1]);
    return 0;
}

