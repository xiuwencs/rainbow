#include "utils.h"
#include <string>
#include <sys/time.h>
#include <fstream>
#include <sstream>
#include "dictionary.h"
//using namespace std;
unsigned long g_scan = 0;
unsigned int g_match = 0;
int literal_num = 0;
clock_t spend = 0;

unsigned long long total = 73385030;
unsigned long long compress = 165299749;
int maxLen = 0;
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
    // printf("acceptVec size = %d\n",acceptVec.size());
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

void GetDictionaryState(short *DictionaryState, FSM *fsm)
{
    const uint8_t *byte = kBrotliDictionaryData;
    state_t start_state = 0;
    for (int i = 0; i < DICTIONARY_BYTES; i++)
    {
        state_t cur_state = fsm->list[start_state * 256 + *byte];
        *DictionaryState = cur_state;
        start_state = cur_state;
        byte++;
        DictionaryState++;
    }
}

short twins_scan(TokenInfo *token, int length, int dist, short *state_array, FSM *fsm, short state)
{
    short *offset = state_array - dist - 1;
    for (int pos = 0; pos < length; pos++, token++, state_array++, offset++)
    {
        if (state == *offset)
        {
			for (int i = 0; i < length - pos; ++i){
				state_array[i] = offset[i + 1];
			}
			/*if(dist >= length){
				memcpy(state_array,offset + 1,sizeof(short) * (length - pos));
			}else{
				 
			}*/
#ifdef ACTION
            for (int i = 0; i < length - pos; ++i)
            {
                if (fsm->accept[state_array[i]] == true)
                    g_match++;
            }
#endif
            return offset[length - pos];
        }
        else
        {
            state = ScanByte(state, token->token, fsm);
            *state_array = state;
            g_scan++;
#ifdef ACTION
            if (fsm->accept[state] == true)
                g_match++;
#endif
        }
    }
    return state;
}

short naive(TokenInfo *token, int length, int dist, short *state_array, FSM *fsm, int state)
{
    for (int pos = 0; pos < length; pos++, token++, state_array++)
    {
        state = fsm->list[state * 256 + token->token];

        *state_array = state;

        if (fsm->accept[state] == true)
            g_match++;

        g_scan++;
    }
    return state;
}

int main(int argc, char **argv)
{
    char *input = argv[1];
    char *rule = argv[2];
    char *accept = argv[3];
    int set = atoi(argv[4]);

    if (set == 1)
    {
        total = 73385030;
        compress = 16234397;
    }
    else if (set == 2)
    {
        total = 226060405;
        compress = 64288836;
    }
    else if (set == 3)
    {
        total = 100000000;
        compress = 35194715;
    }
    else if (set == 4)
    {
        total = 113096550;
        compress = 26260509;
    }
    FSM *fsm = readFromFile(rule, accept);
    vector<m_buffer> buff;
    int size = LoadText(input, buff);
    int *sizArray = new int[size];
    TokenInfo **Txt = new TokenInfo *[size];
    short *stateArray = new short[maxLen]; // store state 320000000

    int literal = 0;

    Init(buff, Txt, sizArray);
    short state = 0;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    int pointer_len = 0;
    int pointer_count = 0;
    for (int i = 0; i < size; i++)
    {
        TokenInfo *token = Txt[i];
        int len = sizArray[i];
        short *states = stateArray;
        state = 0;
        TokenInfo *end = token + len;
        while (token < end)
        {
            if (token->length == 0) // literal
            {
                state = ScanByte(state, token->token, fsm);
                *states = state;
#ifdef ACTION
                if (fsm->accept[state] == true)
                    g_match++;
#endif
                g_scan++;
                states++;
                token++;
                literal_num++;
            }
            else // pointer
            {
                int length = token->length;
                int dist = (token + 1)->dist;
                state = twins_scan(token, length, dist, states, fsm, state);
                states += length;
                token += length;
                pointer_len += length;
                pointer_count++;
            }
        }
    }
    gettimeofday(&tv, NULL);
    long end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    printf("state = %d\n", state);
    printf("time = %d ms\n", end - start);
    printf("scan = %d\n", g_scan);
    printf("match = %d\n", g_match);
    printf("skip ratio = %.2f\n", 100 * (1.0 - (g_scan * 1.0 / total)));
    printf("pointer ratio = %.2f\n", 100 * (1.0 - (literal_num * 1.0 / total)));
    printf("compress ratio = %.2f\n", 100 * (compress * 1.0) / total);
    printf("average pointer len = %.2f\n", (pointer_len * 1.0) / pointer_count);
    delete[] Txt;
}