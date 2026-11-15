#include <bits/stdc++.h>
using namespace std;

class MinMax {
public:
    pair<int, int> find(vector<int>& arr) {
        if (arr.empty()) return {INT_MAX, INT_MIN};
        int mn = arr[0], mx = arr[0];
        for (int x : arr) {
            mn = min(mn, x);
            mx = max(mx, x);
        }
        return {mn, mx};
    }
};

int main() {
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    MinMax mm;
    auto [mn, mx] = mm.find(arr);
    cout << "Min = " << mn << ", Max = " << mx << "\n";
    return 0;
}
