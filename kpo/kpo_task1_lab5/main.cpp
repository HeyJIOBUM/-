#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
using namespace std;
/*bool isOpeningBracket(char testingChar){
    if (testingChar == '{' || testingChar == '(' || testingChar == '[' || testingChar == '<'){
        return true;
    } else return false;
}
bool isClosingBracket(char testingChar){
    if (testingChar == '}' || testingChar == ')' || testingChar == ']' || testingChar == '>'){
        return true;
    } else return false;
}
bool isSameType(char firstChar, char secondChar){
    if ((firstChar == '{' && secondChar == '}') || (firstChar == '[' && secondChar == ']') ||
        (firstChar == '(' && secondChar == ')') || (firstChar == '<' && secondChar == '>')){
        return true;
    } else return false;
}
int main() {
    stack <char> openingBrackets;
    string inputString;
    char temp;
    getline(cin, inputString);
    for (char & i : inputString) {
            if (isOpeningBracket(i)) {
            openingBrackets.push(i);
        } else if (isClosingBracket(i)){
            temp = openingBrackets.top();
            if (isSameType(temp, i)){
                openingBrackets.pop();
            } else {
                cout << "Wrong string!!!!!";
                return 0;
            }
        }
    }
    if (!openingBrackets.empty()){
        cout << "Wrong string!!!!!";
    } else cout << "Correct string!!!!!";
    return 0;
}*/
/*
int main(){
    set <string> uniqueWords;
    string temp, word;
    cout << "Enter text, when it is finished enter STOP\n";
    getline(cin, temp);
    while (temp != "STOP"){
        for (int i = 0; i < temp.size(); i++) {
            while (isalpha(temp[i]) && i < temp.size()){
                word += temp[i];
                i++;
            }
            if (!word.empty() && word.size() > 1) uniqueWords.insert(word);
            word.clear();
        }
        getline(cin, temp);
    }
    for (const auto& i : uniqueWords) {
        cout << i << "   ";
    }
    return 0;
}*/
/*
string findNewestRecord(vector<string> dates){
    int year = 0, month = 0, day = 0;
    string strYear, strMonth, strDay;
    for (auto date : dates){
        int j = 0;
        while (!isdigit(date[j]))j++;
        for (; isdigit(date[j]); ++j) strDay += date[j];
        j++;
        for (; isdigit(date[j]); ++j) strMonth += date[j];
        j++;
        for (; isdigit(date[j]); ++j) strYear += date[j];
        if (year < stoi(strYear)) {
            swap(dates[0], date);
            year = stoi(strYear);
        } else if (year == stoi(strYear) && month < stoi(strMonth)){
            swap(dates[0], date);
            month = stoi(strMonth);
        } else if (year == stoi(strYear) && month == stoi(strMonth) && day < stoi(strDay)){
            swap(dates[0], date);
            day = stoi(strDay);
        }
        strDay.clear();
        strMonth.clear();
        strYear.clear();
    }
    return dates[0];
}
int main(){
    map<string, vector<string>> visitorsList;
    int recordsAmount;
    string visitorInformation, visitorName, visitorDate;
    cout << "Enter the amount of records\n";
    cin >> recordsAmount;
    getline(cin, visitorInformation);
    for (int i = 0; i < recordsAmount; ++i) {
        getline(cin, visitorInformation);
        int j = 0;
        for (; visitorInformation[j] != '-'; ++j) {
            visitorName += visitorInformation[j];
        }
        j++;
        for (; j < visitorInformation.size(); ++j) {
            visitorDate += visitorInformation[j];
        }
        visitorsList[visitorName].push_back(visitorDate);
        visitorName.clear();
        visitorDate.clear();
    }
    for (auto i : visitorsList) {
        cout << i.first << " - " << findNewestRecord(i.second) << "\n";
    }
    return 0;
}*/
