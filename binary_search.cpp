#include <bits/stdc++.h>
using namespace std;

class BinarySearch {
public:
    int search(vector<int>& arr, int target) {
        int left = 0, right = (int)arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return -1;
    }
};

int main() {
    vector<int> arr = {11, 12, 22, 25, 34, 64, 90};
    BinarySearch bs;
    int idx = bs.search(arr, 25);
    if (idx != -1) cout << "Found 25 at index " << idx << "\n";
    else cout << "25 not found\n";
    return 0;
}
