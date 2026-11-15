#include <bits/stdc++.h>
using namespace std;

class CountingSort {
public:
    void sort(vector<int>& arr) {
        if (arr.empty()) return;
        int maxVal = *max_element(arr.begin(), arr.end());
        int minVal = *min_element(arr.begin(), arr.end());
        int range = maxVal - minVal + 1;
        vector<int> count(range, 0), output(arr.size());
        for (int x : arr) count[x - minVal]++;
        for (int i = 1; i < range; i++) count[i] += count[i - 1];
        for (int i = (int)arr.size() - 1; i >= 0; i--) {
            output[count[arr[i] - minVal] - 1] = arr[i];
            count[arr[i] - minVal]--;
        }
        arr = output;
    }
};

int main() {
    vector<int> arr = {4, 2, 2, 8, 3, 3, 1};
    CountingSort s;
    s.sort(arr);
    for (int x : arr) cout << x << " ";
    cout << "\n";
    return 0;
}
