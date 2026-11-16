#include <iostream>
using namespace std;

void findMinMax(int arr[], int left, int right, int &minimum, int &maximum) {
    if (left == right) {
        minimum = maximum = arr[left];
        return;
    }

    int middle = (left + right) / 2;
    int leftMin, leftMax, rightMin, rightMax;

    findMinMax(arr, left, middle, leftMin, leftMax);
    findMinMax(arr, middle + 1, right, rightMin, rightMax);

    minimum = (leftMin < rightMin) ? leftMin : rightMin;
    maximum = (leftMax > rightMax) ? leftMax : rightMax;
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int minimum, maximum;
    findMinMax(arr, 0, n - 1, minimum, maximum);

    cout << "Minimum = " << minimum << "\n";
    cout << "Maximum = " << maximum << "\n";

    delete[] arr;
}
