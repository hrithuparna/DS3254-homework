#include <iostream>
using namespace std;

int getMin(int arr[], int i, int j) {
    int minIndex = i;
    for (int k = i + 1; k <= j; k++) {
        if (arr[k] < arr[minIndex]) {
            minIndex = k;
        }
    }
    return minIndex;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = getMin(arr, i, n - 1);
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
