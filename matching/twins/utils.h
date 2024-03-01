#include <unistd.h>
#include <stdlib.h>
#include <malloc.h>
#include <vector>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <cstring>
#define DICTIONARY_BYTES 122784
using namespace std;
typedef unsigned short state_t;
typedef struct
{
    unsigned char token;
	union
	{
		unsigned short dist;
		unsigned short length;
	};
}TokenInfo;

typedef struct
{
    unsigned char* pBuff;
    size_t size;
}m_buffer;

typedef struct _FSM{
    int *list;
    bool *accept;
}FSM;
inline int ScanByte(short state, unsigned char token, FSM *fsm){
        state = fsm->list[state * 256 + token];
		return state;
};

int LoadText(char* dir, vector<m_buffer>& buff);
//int BR_ScanDist(short state, short* idxArray, TokenInfo * txtArray, int dist, int tlen, DFA* dfa);
//int BR_ScanDict(short state, short* idxArray, TokenInfo* txtArray, int offset, int tlen, short* dictionary_state, DFA* dfa);
//void BrotliCompressMatching(TokenInfo** text, DFA* dfa, int ProcessFileSize[], short* DictionaryState,int count);
//void GetDictionaryState(short* DictionaryState, DFA* dfa);
int Init(vector<m_buffer>& buff, TokenInfo ** Txt, int* sizeArray);
void Performance();

short naive_for_static(TokenInfo *token, int length, short *state_array, FSM *fsm,int state);
short naive_for_dynamic(TokenInfo *token, int length, short *state_array, FSM *fsm,int state);