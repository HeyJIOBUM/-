#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
int main() {
    srand(time(NULL));
    long long neg_sum = 0, pos_sum = 0;
    unsigned int n, repeat;
    cout << "count of the repeats: ";
    cin >> repeat;
    cout << endl;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    cin >> n;
    for (int j = 0; j < repeat; ++j) {
        int* array = new int[n];
        for (int i = 0; i < n; ++i) {
            array[i] = rand() - 16383;
            if (array[i] < 0) neg_sum += array[i];
            else pos_sum += array[i];
        }
        delete[] array;
    }
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    long long int microsecondsDuration = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    cout << endl << microsecondsDuration;
}

