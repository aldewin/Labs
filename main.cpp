#include <iostream>

using namespace std;


int main() {
    int n;
    cin >> n;
    int** arr = new int *[n];
    for (int i = 0; i < n; i++) {
        *(arr + i) = new int[n];
    }

    int num = n + 1;
    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (count++ % 2 == 0) {
            for (int j = 0; j <= i; j++) {
                *(*(arr + i) + j) = num++;
            }
            for (int j = i - 1; j >= 0; j--) {
                arr[j][i] = num++;
            }
        } else {
            for (int j = 0; j <= i; j++) {
                *(*(arr + j) + i) = num++;
            }
            for (int j = i - 1; j >=0 ; j--) {
                *(*(arr + i) + j) = num++;
            }
        }

    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << *(*(arr + i) +  j) << " ";
        }
        cout << endl;
    }

    return 0;
}