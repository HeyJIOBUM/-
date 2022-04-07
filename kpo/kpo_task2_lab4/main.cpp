#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;
string openFile();
void fillDigitsFromFile(int *digits, const string& fileName);
void fillNumbersFromFile(int*& numbers, int* numbersCount, const string& fileName);
void showAllDigitsInFile(int *digits);
void showAllNumbersInFile(int *numbers, int numbersCount);
void insertionSort(int* numbers, int numbersCount);
int digitsInTheNum(int number);
int main() {
    string fileName = openFile();
    int numbersCount = 0;
    int* numbers = new int[numbersCount];
    int digits[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    fillDigitsFromFile(digits, fileName);
    fillNumbersFromFile(numbers, &numbersCount, fileName);
    showAllDigitsInFile(digits);
    showAllNumbersInFile(numbers, numbersCount);
    return 0;
}
int digitsInTheNum(int number){
    int n  = 1;
    while (number != 0) {
        n++;
        number /= 10;
    }
    return n;
}
void insertionSort(int* numbers, int numbersCount){
    for (int step = 1; step < numbersCount; step++) {
        int key = numbers[step];
        int j = step - 1;
        while (key < numbers[j] && j >= 0) {
            numbers[j + 1] = numbers[j];
            --j;
        }
        numbers[j + 1] = key;
    }
}
void showAllNumbersInFile(int *numbers, int numbersCount) {
    cout << "All numbers from the text: \n";
    insertionSort(numbers, numbersCount);
    for (int i = 0; i < numbersCount - 1; ++i) {
        int j = 1;
        while (numbers[i] == numbers[i + 1]){
            i++;
            j++;
        }
        cout << numbers[i] << " occurs in the text " << j << " times \n";
    }

}
void showAllDigitsInFile(int *digits) {
    for (int i = 0; i < 10; ++i) {
        cout << i << " occurs in the text " << digits[i] << " times \n";
    }
}
void fillNumbersFromFile(int*& numbers, int* numbersCount, const string& fileName) {
    ifstream file(fileName);
    string buffer;
    int *temp;
    while (!file.eof()) {
        getline(file, buffer);
        for (int charPosInFile = 0; charPosInFile <= buffer.size(); ++charPosInFile) {
            if (isdigit(buffer[charPosInFile])) {
                temp = new int[*numbersCount + 1];
                for (int k = 0; k < *numbersCount; k++) {
                    temp[k] = numbers[k];
                }
                delete numbers;
                numbers = temp;
                numbers[*numbersCount] = stoi(&buffer[charPosInFile]);
                charPosInFile += digitsInTheNum(numbers[*numbersCount]) - 1;
                (*numbersCount)++;

            }
        }
    }
    //cout << *numbersCount << endl;
    file.close();
}
void fillDigitsFromFile(int *digits, const string& fileName){
    ifstream file (fileName);
    char buffer;
    while (!file.eof()) {
        file.get(buffer);
        if (isdigit(buffer)) {
            digits[(int) buffer - '0']++;
        }
        buffer = ' ';
    }
    file.close();
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
        return openFile();
    }
}