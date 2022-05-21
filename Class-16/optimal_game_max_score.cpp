#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> memo;

int max_score_helper(vector<int> &A, int i, int j) {

    if (i > j) {
        return 0;
    }
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // CASE-1: Choose A[i]
    int sub_result_1 = A[i] + min(max_score_helper(A, i + 2, j), 
                                  max_score_helper(A, i + 1, j - 1));

    // CASE-2: Choose A[j]
    int sub_result_2 = A[j] + min(max_score_helper(A, i + 1, j - 1),
                                  max_score_helper(A, i, j - 2));
    

    return memo[i][j] = max(sub_result_1, sub_result_2);
}

int max_score(vector<int> A) {

    int n = A.size();
    memo = vector<vector<int>> (n, vector<int> (n, -1));
    return max_score_helper(A, 0, A.size() - 1);
}

int main() {

    cout << max_score({5, 3, 7, 10}) << endl;
    cout << max_score({8, 15, 3, 7}) << endl;
}