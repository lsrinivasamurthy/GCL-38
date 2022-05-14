#include<bits/stdc++.h>
using namespace std;

// TC: O(n * m)
// Aux Space: O(n * m)
vector<vector<int>> memo;
// This function will return the LCS of s1[i ... n-1] and s2[j ... m-1].
int lcs_helper(string &s1, int i, string &s2, int j) {

    // Base cases
    if (i == s1.length() or j == s2.length()) {
        return 0;
    }

    // If the result of the current state has already been evaluated, return it.
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Store the result of the current state and return it.
    if (s1[i] == s2[j]) {
        return memo[i][j] = 1 + lcs_helper(s1, i + 1, s2, j + 1);
    }

    return memo[i][j] = max(lcs_helper(s1, i, s2, j + 1), lcs_helper(s1, i + 1, s2, j));
}

int lcs(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    memo = vector<vector<int>> (n, vector<int> (m, -1));
    return lcs_helper(s1, 0, s2, 0);
}

// TC: O(n * m)
// Aux Space: O(n * m)
int lcs_bottom_up(string s1, string s2) {

    int n = s1.length();
    int m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));

    // Accommodate the base cases by filling the 0th row and 0th column with 0.
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {

    cout << lcs("ABCDGH", "AEDFHR") << endl;
    cout << lcs("ABC", "AC") << endl;

    cout << lcs_bottom_up("ABCDGH", "AEDFHR") << endl;
    cout << lcs_bottom_up("ABC", "AC") << endl;
}
