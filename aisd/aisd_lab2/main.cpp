#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
void counting_sort(int* array, int n){

}
void quick_sort(int* array, int n){

}
void insertion_sort(int* array, int n){

}
int main() {
    srand(time(NULL));
    unsigned int n;
    cin >> n;
    chrono::steady_clock::time_point begin = chrono::steady_clock::now();
    int* array = new int[n];
    for (int i = 0; i < n; ++i) array[i] = rand() * 3;
    counting_sort(array,n);
    delete[] array;
    chrono::steady_clock::time_point end = chrono::steady_clock::now();
    long long int microsecondsDuration = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    cout << endl << microsecondsDuration;


    begin = chrono::steady_clock::now();
    array = new int[n];
    for (int i = 0; i < n; ++i) array[i] = rand() * 3;
    insertion_sort(array,n);
    delete[] array;
    end = chrono::steady_clock::now();
    microsecondsDuration = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    cout << endl << microsecondsDuration;


    begin = chrono::steady_clock::now();
    array = new int[n];
    for (int i = 0; i < n; ++i) array[i] = rand() * 3;
    quick_sort(array,n);
    delete[] array;
    end = chrono::steady_clock::now();
    microsecondsDuration = chrono::duration_cast<chrono::microseconds>(end - begin).count();
    cout << endl << microsecondsDuration;
}

for i = 0 to k - 1
C[i] = 0;
for i = 0 to n - 1
C[A[i]] = C[A[i]] + 1;
b = 0;
for j = 0 to k - 1
for i = 0 to C[j] - 1
A[b] = j;
b = b + 1;