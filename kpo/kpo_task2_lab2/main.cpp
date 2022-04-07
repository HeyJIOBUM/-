#include <iostream>
using namespace std;
bool answ(){
    unsigned int car_price = 0, car_count = 0, motorcycle_price = 0, motorcycle_count = 0, current_price = -1;
    cout << "Write the price of the motorcycle or the car, to stop entering write 0 " << endl;
    while (current_price != 0){
        cin >> current_price;
        if (current_price > 5000){
            car_price += current_price;
            car_count++;
        }
        else if (current_price <= 5000){
            motorcycle_price += current_price;
            motorcycle_count++;
        }
    }
    if (car_count == 0 || motorcycle_count == 0) return 3;
    return (car_price / car_count > 3 * motorcycle_price / motorcycle_count);
}
int main() {
    for (int i = 0; i < 3; i++) {
        bool task = answ();
        if (task == 1) {
            cout << "the average cost of cars exceeds the average cost of motorcycles by more than 3 times" << endl;
        } else if (task == 0) cout << "the average cost of cars does not exceed the average cost of motorcycles by more than 3 times" << endl;
        else cout << "Car count or motorcycle count = 0";
    }
    return 0;
}
