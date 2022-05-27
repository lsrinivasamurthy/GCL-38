#include<bits/stdc++.h>
using namespace std;

// TC: O(n * W)
// Aux Space: O(n * W)

vector<vector<int>> memo;

int max_value_helper(vector<int> &values, vector<int> &weights, int i, int W) {

    if (i == values.size()) { // If no items are left.
        return 0;
    }
    if (W == 0) { // If the remaining of the knapsack is zero.
        return 0;
    }

    if (memo[i][W] != -1) {
        return memo[i][W];
    }

    if (weights[i] > W) {
        return memo[i][W] = max_value_helper(values, weights, i + 1, W);
    }

    int result = max(max_value_helper(values, weights, i + 1, W - weights[i]) + values[i], // Considering the current item.
                     max_value_helper(values, weights, i + 1, W));                         // Ignoring the current item.

    
    return memo[i][W] = result;
}

int max_value(vector<int> values, vector<int> weights, int W) {
    
    int n = values.size();
    memo = vector<vector<int>> (n, vector<int> (W + 1, -1));
    return max_value_helper(values, weights, 0, W);
}

int max_value_bottom_up(vector<int> values, vector<int> weights, int W) {

    int n = values.size();
    vector<vector<int>> dp(n + 1, vector<int> (W + 1));

    for (int j = 0; j <= W; j++) { // If there is no item under consideration.
        dp[0][j] = 0;
    }
    for (int i = 0; i <= n; i++) { // If the capacity of the knapsack is zero.
        dp[i][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            
            if (weights[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j] = max(dp[i - 1][j - weights[i - 1]] + values[i - 1], // Considering the current item.
                               dp[i - 1][j]);                                 // Ignoring the current item.
            }
        }
    }

    return dp[n][W];
}

int main() {

    cout << max_value({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value({60, 100, 120}, {10, 20, 50}, 50) << endl;

    cout << max_value_bottom_up({60, 100, 120}, {10, 20, 30}, 50) << endl;
    cout << max_value_bottom_up({60, 100, 120}, {10, 20, 50}, 50) << endl;
}