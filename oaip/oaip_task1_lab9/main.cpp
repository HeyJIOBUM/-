#include <iostream>
#include <iomanip>
using namespace std;
void Smooth2(double* A, int N);
void display(double* A, int N);
void input_array(double* A, int N);
int main() {
    double A[256];
    int N;
    cout << "Enter the size of the array-";
    cin >> N;
    cout << "Enter array elements-";
    input_array(A, N);
    for (int i = 0; i < 5; i++) {
        Smooth2(A, N);
        display(A, N);
        cout << endl;
    }
    return 0;
}
void Smooth2(double* A, int N){
    for (int i = 1; i < N; i++){
        A[i] = (A[i] + A[i - 1]) / 2;
    }
}
void display(double* A, int N){
    for (int i = 0; i < N; i++){
        cout << setprecision(3) << A[i] << " ";
    }
}
void input_array(double* A, int N){
    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
}
