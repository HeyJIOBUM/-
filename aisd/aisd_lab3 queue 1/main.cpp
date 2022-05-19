#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;
int main() {
    queue <int> firstQueue;
    queue <int> secondQueue;
    queue <int> requiredQueue;
    int amount;
    int temp;
    cout << "Enter the number of elements in one queue\n";
    cin >> amount;
    cout << "Enter the elements of the first queue\n";
    for (int i = 0; i < amount; ++i) {
        cin >> temp;
        firstQueue.push(temp);
    }
    cout << "Enter the elements of the second queue\n";
    for (int i = 0; i < amount; ++i) {
        cin >> temp;
        secondQueue.push(temp);
    }
    for (int i = 0; i < amount; ++i) {
        requiredQueue.push(firstQueue.front());
        firstQueue.pop();
        requiredQueue.push(secondQueue.front());
        secondQueue.pop();
    }
    cout << "New queue:\n";
    for (int i = 0; i < amount * 2; ++i) {
        cout << requiredQueue.front() << " ";
        requiredQueue.pop();
    }
    return 0;
}