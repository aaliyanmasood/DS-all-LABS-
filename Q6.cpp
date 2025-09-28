#include <iostream>
using namespace std;

int recursiveArraySum(void* arr, int sizes[], int dim) {
    int sum = 0;
    if (dim == 1) {
        int* baseArr = (int*)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += baseArr[i];
        }
    } else {
        void** subArr = (void**)arr;
        for (int i = 0; i < sizes[0]; i++) {
            sum += recursiveArraySum(subArr[i], sizes + 1, dim - 1);
        }
    }
    return sum;
}

int main() {
    int*** arr = new int**[2];
    for (int i = 0; i < 2; i++) {
        arr[i] = new int*[2];
        for (int j = 0; j < 2; j++) {
            arr[i][j] = new int[2];
            for (int k = 0; k < 2; k++) {
                arr[i][j][k] = i + j + k;
            }
        }
    }

    int sizes[] = {2, 2, 2};
    int sum = recursiveArraySum((void*)arr, sizes, 3);
    cout << sum << endl;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            delete[] arr[i][j];
        }
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}
