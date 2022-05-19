#include <iostream>
#include <stack>
#include <string>
using namespace std;
void checkTags(string inputString, stack <string>& tags){
    string temp;
    for (int i = 0; i < inputString.size(); ++i) {
        if (inputString[i] == '<'){
            i++;
            while (inputString[i] != '>' && inputString[i] != ' ' && i < inputString.size()){
                temp += inputString[i];
                i++;
            }
            if (temp[0] == '/'){
                if (tags.empty()) {
                    cout << "Tag " << temp << " does not have a pair\n";
                    return;
                } else if (temp != '/' + tags.top()){
                    cout << "Tag " << tags.top() << " does not have a pair, you should fix the tag " << temp << "\n";
                    return;
                } else {
                    tags.pop();
                }
            } else {
                tags.push(temp);
            }
            temp.clear();
        }
    }
    if (tags.empty()) cout << "The HTML code is correct\n";
    else cout << "Tag " << tags.top() << " does not have a pair\n";
    while (!tags.empty())tags.pop();
}
int main() {
    stack <string> tags;
    string inputString;
    int mode;
    do {
        cout << "Press '1' to enter the HTML code, press '2' to exit from the app\n";
        cin >> mode;
        if (mode == 1){
            cout << "Enter code:\n";
            cin.get();
            getline(cin, inputString);
            checkTags(inputString, tags);
        }
    } while (mode != 2);
    return 0;
}
