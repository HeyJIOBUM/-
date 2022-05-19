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
    cout << "Enter the number of elements in the first queue\n";
    cin >> amount;
    cout << "Enter the elements of the first queue\n";
    for (int i = 0; i < amount; ++i) {
        cin >> temp;
        firstQueue.push(temp);
    }
    cout << "Enter the number of elements in the first queue\n";
    cin >> amount;
    cout << "Enter the elements of the second queue\n";
    for (int i = 0; i < amount; ++i) {
        cin >> temp;
        secondQueue.push(temp);
    }
    while (!firstQueue.empty() && !secondQueue.empty()){
        if (firstQueue.front() <= secondQueue.front()){
            requiredQueue.push(firstQueue.front());
            firstQueue.pop();
        } else {
            requiredQueue.push(secondQueue.front());
            secondQueue.pop();
        }
    }
    if (!firstQueue.empty() || !secondQueue.empty()){
        while (!secondQueue.empty()){
            requiredQueue.push(secondQueue.front());
            secondQueue.pop();
        }
        while (!firstQueue.empty()){
            requiredQueue.push(firstQueue.front());
            firstQueue.pop();
        }
    }
    while (!requiredQueue.empty()){
        cout << requiredQueue.front() << " ";
        requiredQueue.pop();
    }
    return 0;
}