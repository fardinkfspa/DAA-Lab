#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i = left; i <= right; i++) arr[i] = temp[i];
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergeSort(arr, temp, left, mid);
    mergeSort(arr, temp, mid + 1, right);
    merge(arr, temp, left, mid, right);
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    int *temp = new int[n];

    cout << "Enter the numbers: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, temp, 0, n - 1);

    cout << "Sorted numbers: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << "\n";

}
