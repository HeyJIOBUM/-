#include <iostream>
#include <cstring>
using namespace std;
int PosLast(char* S0, char* S);
int main(){
    char S0[256];
    char S[256];
    for (int i = 0; i < 5; i++) {
        cout << "Find a string:" << endl;
        gets(S0);
        cout << "In a string:" << endl;
        gets(S);
        cout << "Position of the last entry - " << PosLast(S0, S) << endl;
    }
    return 0;
}
int PosLast(char* S0, char* S){
    char* start = S;
    char* cur_entry = S;
    int pos;
    while (strstr(S,S0) != NULL){
        cur_entry = strstr(S,S0);
        S++;
    }
    pos = cur_entry - start;
    return pos;
}
