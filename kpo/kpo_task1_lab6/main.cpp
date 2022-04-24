#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>
#include <fstream>
using namespace std;
/*int main() {
    int maxElements[4] {INT_MIN, INT_MIN, INT_MIN, INT_MIN};
    int numberOfElements, maxIndex;
    cin >> numberOfElements;
    if (numberOfElements < 4) return 0;
    int array[numberOfElements];
    for (int i = 0; i < numberOfElements; ++i) {
        cin >> array[i];
    }
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < numberOfElements; ++i) {
            if (maxElements[j] < array[i]){
                maxElements[j] = array[i];
                maxIndex = i;
            }
        }
        array[maxIndex] = INT_MIN;
    }
    for (auto maxElement : maxElements) {
        cout << maxElement << "  ";
    }
    return 0;
}*/
/*
int main() {
    vector <int> primeNumbers;
    int numberLimit;
    cin >> numberLimit;
    bool allNumbers[numberLimit + 1];
    for (int i = 0; i < numberLimit + 1; ++i) allNumbers[i] = true;
    for (int i = 2; i < numberLimit + 1; ++i) {
        if (allNumbers[i]){
            primeNumbers.push_back(i);
            for (int j = i * i; j < numberLimit + 1; j += i){
                allNumbers[j] = false;
            }
        }
    }
    for (auto primeNumber : primeNumbers) {
        cout << primeNumber << "  ";
    }
}*/
/*int main() {
    int numbersAmount, tempSum = 0, localMax = 0;
    cin >> numbersAmount;
    int numbersArray[numbersAmount];
    vector <int> tempVector;
    vector <int> answer;
    for (int i = 0; i < numbersAmount; ++i) {
        cin >> numbersArray[i];
        if (tempSum + numbersArray[i] > localMax) {
            tempVector.push_back(numbersArray[i]);
            answer = tempVector;
            localMax = tempSum + numbersArray[i];
        } else if (tempSum + numbersArray[i] <= 0) {
            tempVector.clear();
            tempSum = 0;
            continue;
        } else if (tempSum + numbersArray[i] > 0){
            tempVector.push_back(numbersArray[i]);
        }
        tempSum += numbersArray[i];
    }
    cout << localMax << ": ";
    for (auto item : answer) {
        cout << item << "  ";
    }
    return 0;
}*/
/*
void getSequence(vector <int>* answer, vector <pair <int, int>> numbersVector, int position){
    int correctPosition = position, maxIndex = 0;
    if (numbersVector[position].second == 1){
        answer->push_back(numbersVector[position].first);
        return void();
    }
    for (int i = 0; i < position; ++i) {
        if (numbersVector[i].second > maxIndex && numbersVector[i].first < numbersVector[position].first){
            maxIndex = numbersVector[i].second;
            correctPosition = i;
        }
    }
    getSequence(answer, numbersVector, correctPosition);
    answer->push_back(numbersVector[position].first);
}
int getIndex(int numberFromVector, const vector <pair <int, int>>& numbersVector){
    int index = 1;
    for (auto item: numbersVector) {
        if (item.first < numberFromVector && item.second >= index){
            index = item.second + 1;
        }
    }
    return index;
}
int main(){
    int numbersAmount, tempInt, maxIndex = 0, maxElementPosition;
    cin >> numbersAmount;
    vector <int> answer;
    vector <pair <int, int>> numbersVector;
    for (int i = 0; i < numbersAmount; ++i) {
        cin >> tempInt;
        numbersVector.push_back(make_pair(tempInt, getIndex(tempInt, numbersVector)));
    }
    for (int i = 0; i < numbersVector.size(); i++) {
        if (numbersVector[i].second > maxIndex){
            maxElementPosition = i;
            maxIndex = numbersVector[i].second;
        }
    }
    getSequence(&answer, numbersVector, maxElementPosition);
    cout << answer.size() << ": ";
    for (auto item : answer) {
        cout << item << "  ";
    }
    return 0;
}
*/
