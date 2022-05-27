#include<bits/stdc++.h>
using namespace std;

// TC: O(n * m)
// Aux Space: O(n * m)

vector<vector<int>> memo;

int get_min_steps_helper(string &A, string &B, int i, int j) {
    if (i == A.length()) { // Insert all the remaining characters present in B.
        return B.length() - j;
    }
    if (j == B.length()) { // Delete all the remaining characters present in A.
        return A.length() - i;
    }

    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    if (A[i] == B[j]) {
        return memo[i][j] = get_min_steps_helper(A, B, i + 1, j + 1);
    }

    // Try Inserting.
    int result = 1 + get_min_steps_helper(A, B, i, j + 1);

    // Try Deleting.
    result = min(result, 1 + get_min_steps_helper(A, B, i + 1, j));

    // Try Replacing.
    result = min(result, 1 + get_min_steps_helper(A, B, i + 1, j + 1));

    return memo[i][j] = result;
}

int get_min_steps(string A, string B) {

    int n = A.length();
    int m = B.length();
    memo = vector<vector<int>> (n, vector<int> (m, -1));
    return get_min_steps_helper(A, B, 0, 0);
}

int main() {

    cout << get_min_steps("abad", "abac") << endl;
    cout << get_min_steps("Anshuman", "Antihuman") << endl;
}