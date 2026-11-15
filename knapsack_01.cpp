#include <bits/stdc++.h>
using namespace std;

class Knapsack01 {
public:
    int solve(int capacity, vector<int>& weights, vector<int>& values) {
        int n = weights.size();
        vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int w = 0; w <= capacity; w++) {
                if (weights[i - 1] <= w)
                    dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
                else
                    dp[i][w] = dp[i - 1][w];
            }
        }
        return dp[n][capacity];
    }
};

int main() {
    int capacity = 7;
    vector<int> weights = {1, 3, 4, 5};
    vector<int> values  = {1, 4, 5, 7};
    Knapsack01 k;
    cout << "Max value = " << k.solve(capacity, weights, values) << "\n";
    return 0;
}
