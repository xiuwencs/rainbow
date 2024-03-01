#include "utils.h"
#include <string>
#include <sys/time.h>
#include <fstream>
#include <sstream>
#include "dictionary.h"

unsigned long g_scan = 0;
unsigned int g_match = 0;
int literal_num = 0;
clock_t spend = 0;

unsigned long long total = 73385030;
unsigned long long compress = 165299749;

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

int main(int argc, char **argv)
{
    char *input = argv[1];
    char *rule = argv[2];
    char *accept = argv[3];
    FSM *fsm = readFromFile(rule, accept);
    vector<m_buffer> buff;
    int size = LoadText(input, buff); // load data
    int *sizArray = new int[size];
    unsigned char **Txt = new unsigned char *[size];
    Init(buff, Txt, sizArray);
    struct timeval tv;
    gettimeofday(&tv, NULL);
    long start = tv.tv_sec * 1000 + tv.tv_usec / 1000;

    short state = 0;
    for (int i = 0; i < size; i++)
    {
        unsigned char *token = Txt[i];
        int len = sizArray[i];
        state = 0;
        for (int j = 0; j < len; j++)
        {
            state = fsm->list[state * 256 + token[j]];
            //if(fsm->accept[state] == true) g_match++;
            g_scan++;
        }
    }
    gettimeofday(&tv, NULL);
    long end = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    printf("state = %d\n", state);
    printf("g_scan = %d\n", g_scan);
    printf("time = %d ms\n", end - start);
    printf("match = %d\n", g_match);
    delete[] Txt;
}