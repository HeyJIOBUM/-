#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
void findVariables(const string&, int);
string openFile();
int isVariableInString(const string& lineFromFile);
int main() {
    int firstSameNumb;
    string fileName = openFile();
    cout << "Compare first 'x' characters:";
    cin >> firstSameNumb;
    findVariables(fileName, firstSameNumb);
    return 0;
}
string openFile(){
    string fileName;
    cout << "Enter file name:";
    cin >> fileName;
    ifstream file (fileName);
    if (file.is_open()) {
        file.close();
        return fileName;
    }
    else {
        cout << "File opening error, please try again" << endl;
        openFile();
    }
}
void findVariables(const string& fileName, int firstSameNumb){
    string variables[100];
    int identifiersCounter = 0;
    string buffer;
    int variablePosition;
    ifstream fin (fileName);
    while (!fin.eof()){
        variablePosition = 0;
        getline(fin, buffer);
        variablePosition = isVariableInString(buffer);
        if (variablePosition != 0){
            for (int i = variablePosition, k = 0; buffer[i] != ';'; ++i) {
                if (buffer[i] == ','){
                    if (k >= firstSameNumb){
                        variables[identifiersCounter][k] = '\0';
                        identifiersCounter++;
                    }
                    k = 0;
                    i++;
                }
                else if (buffer[i] == '='){
                    i = (int)buffer.find(',', i);
                    if (k >= firstSameNumb){
                        variables[identifiersCounter][k] = '\0';
                        identifiersCounter++;
                    }
                    k = 0;
                    i++;
                }
                else{
                    variables[identifiersCounter][k] = buffer[i];
                    k++;
                    i++;
                }
            }
        }
    }
    fin.close();
    sort (variables->begin(), variables->end());
    for (int i = 0; i < identifiersCounter; ++i) {
        if (true){
            ;
        }
    }
}
int isVariableInString(const string& lineFromFile) {
    string typesOfVariables[6] = { "int", "char", "double", "string", "float", "bool"};
    int variablePosition;
    for (int i = 0; i < 6; ++i) {
        variablePosition = (int)lineFromFile.find(typesOfVariables[i]);
        if (variablePosition != -1){
            return (int)typesOfVariables[i].length() + variablePosition;
        }
    }
    return 0;
}

