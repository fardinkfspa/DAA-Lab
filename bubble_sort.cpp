#include <iostream>
using namespace std;

int main() {
    int n;
    int arr[100];

    cout << "Enter number of elements (1-100): ";
    cin >> n;

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Sorted: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
}
