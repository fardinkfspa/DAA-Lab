#include <bits/stdc++.h>
using namespace std;

class QuickSort {
private:
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
public:
    void sort(vector<int>& arr) {
        quickSort(arr, 0, (int)arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    QuickSort s;
    s.sort(arr);
    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}
