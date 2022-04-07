#include <iostream>
#include <cassert>
using namespace std;
void necessary_banknotes(int count){
    int pow_of_two = 64;
    cout << count << ":" << endl;
    while(count >= 1) {
        if (count / pow_of_two != 0) {
        cout << "banknotes worth " << pow_of_two << ":" << count / pow_of_two << endl;
        }
        count = count % pow_of_two;
        pow_of_two = pow_of_two / 2;
    }
}
int main() {
    int price;
    cout << "input price:";
    cin >> price;
    for (int i = 0; i <= 10;i++){
        necessary_banknotes(price + i);
    }
    return 0;
}
