#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <cstring>
#include <fstream>
#include <sstream>
using namespace std;
#define DICTIONARY_BYTES 122784
typedef union meta
{
	unsigned int count;
	unsigned int copy_len;
	int index;
}m;

typedef struct
{
	unsigned char* contents;
	m* meta;
	size_t metaLength;
}Input;


typedef struct
{
	unsigned char* pBuff;
	size_t size;
}m_buffer;

typedef struct _FSM {
	int* list;
	bool* accept;
}FSM;

inline int ScanByte(short &state, unsigned char token, FSM* fsm) {
	state = fsm->list[state * 256 + token];
	return state;
};

int readFileName(char *path,vector<string> &name);

int LoadText(char *path, vector<m_buffer> &buff,vector<string> &name);

void GetDictionaryState(short* DictionaryState, FSM* fsm);

int BrInit(vector<m_buffer>& contentsBuf, vector<m_buffer>& metaBuf, Input** Txt);
void Performance();
short naive_for_static(Input* token, int length, short* state_array, FSM* fsm, short state);
short naive_for_dynamic(Input* token, int length, short* state_array, FSM* fsm, short state);

short rainbow_for_dynamic(Input* token, int length, int dist, short* state_array, FSM* fsm, short state);
short rainbow_for_static(Input* token, int length, int index, short* state_array, FSM* fsm, short state, short* dictionary);

FSM* readFromFile(char* tableFile, char* acceptFile);

short SkipStaticPointer(unsigned char* dictionary, int length, int index, FSM* fsm, short state, short* stateArray, int position);

short SkipDynamicPointer(unsigned char* contents, int length, int index, FSM* fsm, short state, short* stateArray, int position);