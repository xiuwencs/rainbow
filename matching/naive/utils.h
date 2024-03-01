#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#define DICTIONARY_BYTES 122784
typedef struct
{
    unsigned char* pBuff;
    size_t size;
}m_buffer;

typedef struct _FSM{
    int *list;
    bool *accept;
}FSM;


using namespace std;

int LoadText(char* dir, vector<m_buffer>& buff);
void BrotliCompressMatching(unsigned char** text, FSM *fsm, int ProcessFileSize[], short* DictionaryState,int count);
int Init(vector<m_buffer>& buff, unsigned char** Txt, int* sizeArray);
void Performance();