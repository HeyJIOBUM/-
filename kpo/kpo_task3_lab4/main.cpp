#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void fillReverseFile(string* fileLines, int amountOfLines, const string& fileName);
void fillFileLines(string* fileLines, int amountOfLines, const string& fileName);
string openFile();
int findAmountOfLines(const string& fileName);
int main() {
    int amountOfLines;
    string fileName = openFile();
    amountOfLines = findAmountOfLines(fileName);
    string fileLines[amountOfLines];
    fillFileLines(fileLines, amountOfLines, fileName);
    fillReverseFile(fileLines, amountOfLines, fileName);
}
void fillFileLines(string* fileLines, int amountOfLines, const string& fileName){
    ifstream fin (fileName);
    for (int i = 0; i < amountOfLines; ++i) {
        getline(fin, fileLines[i]);
    }
    fin.close();
}
int findAmountOfLines(const string& fileName) {
    int amountOfLines = 0;
    string buffer;
    ifstream fin (fileName);
    while (!fin.eof()){
        getline(fin,buffer);
        amountOfLines++;
    }
    return amountOfLines;
}

string openFile(){
    string fileName;
    cout << "Enter file name:";
    cin >> fileName;
    ifstream file (fileName);
    if (file.is_open()) {
        file.close();
        ofstream reversefile ("Reverse" + fileName);
        return fileName;
    }
    else {
        cout << "File opening error, please try again" << endl;
        return openFile();
    }
}
void fillReverseFile(string* fileLines, int amountOfLines, const string& fileName){
    ofstream fout ("Reverse" + fileName);
    for (int i = amountOfLines - 1; i >= 0; --i) {
        for (int j = (int)fileLines[i].size() - 1; j >= 0; --j) {
            fout.put(fileLines[i][j]);
        }
        fout.put('\n');
    }
    fout.close();
}