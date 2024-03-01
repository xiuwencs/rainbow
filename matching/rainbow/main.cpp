#include "utils.h"
#include <string>
#include "dictionary.h"
#include <algorithm>
#include <sys/time.h>

unsigned long g_scan = 0;
unsigned int g_match = 0;
int literal_num = 0;
clock_t spend = 0;
short *global;
int g_index = 0;
unsigned long long total = 73385030;
unsigned long long compress = 165299749;
int maxLen = 0;

int main(int argc, char **argv)
{
    char *_input = argv[1];
    char *_meta = argv[2];
    char *rule = argv[3];
    char *accept = argv[4];
    int set = atoi(argv[5]);

    if (set == 1)	// Alexa
    {
        total = 73385030;
        compress = 12397003;
    }
    else if (set == 2) // Google
    {
        total = 226060405;
        compress = 53840635;
    }
    else if (set == 3) // Enwik
    {
        total = 100000000;
        compress = 25742001;
    }
    else if (set == 4) // COVID-19
    {
        total = 113096550;
        compress = 7364753;
    }

    FSM *fsm = readFromFile(rule, accept);

    vector<m_buffer> contents;
    vector<m_buffer> metaInput;

    vector<string> InputName;
    vector<string> MetaName;

    readFileName(_input, InputName);
    readFileName(_meta, MetaName);

    //排序
    sort(InputName.begin(), InputName.end());
    sort(MetaName.begin(), MetaName.end());

    
    for (int i = 0; i < InputName.size(); i++)
    {
        struct stat statbuf;
        string input = InputName[i];
        stat(input.c_str(), &statbuf);
        unsigned char *pBuf = (unsigned char *)malloc(statbuf.st_size);
        FILE *hFile = fopen(input.c_str(), "rb");
        fread(pBuf, statbuf.st_size, 1, hFile);
        contents.push_back({pBuf, static_cast<size_t>(statbuf.st_size)});

        string meta = MetaName[i];
        stat(meta.c_str(), &statbuf);
        unsigned char *pBuf1 = (unsigned char *)malloc(statbuf.st_size);
        hFile = fopen(meta.c_str(), "rb");
        fread(pBuf1, statbuf.st_size, 1, hFile);
        fclose(hFile);
        metaInput.push_back({pBuf1, static_cast<size_t>(statbuf.st_size)});
    }

    int size = contents.size();
    short *stateArray = new short[DICTIONARY_BYTES + 320000000];
    GetDictionaryState(stateArray, fsm);

    int *metaSize = new int[size];
    int *contentSize = new int[size];

    for (int i = 0; i < size; i++)
    {
        metaSize[i] = metaInput[i].size / sizeof(meta);
        contentSize[i] = contents[i].size;
    }

    short state = 0;
    int pointer_len = 0;
    int pointer_count = 0;
    int pos;

    struct timeval tv;
    gettimeofday(&tv,NULL);
    long start = tv.tv_sec*1000 + tv.tv_usec/1000;
    for (int i = 0; i < size; i++)
    {
        unsigned char *content = contents[i].pBuff;
        meta *m = (meta *)metaInput[i].pBuff;
        int metaLength = metaSize[i];
        pos = 0;
        state = 0;
        int start = 0;
        for (int j = 0; j < metaLength; j += 3)
        {
            unsigned int uncompress = m[j].count;
            unsigned int copyLen = m[j + 1].copy_len;
            for (int k = 0; k < uncompress; k++)
            {
                ScanByte(state, content[pos], fsm);
                stateArray[pos + DICTIONARY_BYTES] = state;
                g_scan++;
                pos++;
#ifdef ACTION
                if (fsm->accept[state] == true)
                {
                    g_match++;
                }
#endif
                literal_num++;
            }
            // scan pointer
            if (copyLen > 0)
            {
                int index = m[j + 2].index;
                if (index < 0)
                {
                    state = SkipDynamicPointer(content, copyLen, index, fsm, state, stateArray, pos);
                }
                else
                {
                    state = SkipStaticPointer(kBrotliDictionaryData, copyLen, index, fsm, state, stateArray, pos);
                }
                pos += copyLen;
                pointer_len += copyLen;
                pointer_count++;
            }
        }
    }
    gettimeofday(&tv,NULL);
    long end = tv.tv_sec*1000 + tv.tv_usec/1000;
    printf("time = %d\n", (end - start));
    printf("state = %d\n", state);
    printf("scan = %d\n", g_scan);
    printf("match = %d\n", g_match);
    //printf("scan ratio = %.2f\n", 100 * (g_scan * 1.0 / total));
    printf("skip ratio = %.2f\n", 100.0 - 100 * (g_scan * 1.0 / total));
    printf("pointer ratio = %.2f\n", 100 * (1.0 - (literal_num * 1.0 / total)));
    printf("compress ratio = %.2f\n", 100 * (compress * 1.0) / total);
    printf("average pointer len = %.2f\n", (pointer_len * 1.0) / pointer_count);

    delete[] fsm->accept;
    delete[] fsm->list;
    delete[] stateArray;
    delete fsm;
    for (int i = 0; i < contents.size(); i++)
    {
        delete contents[i].pBuff;
        delete metaInput[i].pBuff;
    }
}