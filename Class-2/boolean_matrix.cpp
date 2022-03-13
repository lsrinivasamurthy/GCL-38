#include<bits/stdc++.h>
using namespace std;

// TC: O(m*n)
// Aux Space: O(1)
vector<vector<int>> set_matrix_zeros(vector<vector<int>> arr) {

    int n = arr.size();
    int m = arr[0].size();

    // STEP-1: Check if the 0th row and the 0th col contains any zero.
    bool zeroth_row = false;
    bool zeroth_col = false;

    for (int j = 0; j < m; j++) {
        if (arr[0][j] == 0) {
            zeroth_row = true;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        if (arr[i][0] == 0) {
            zeroth_col = true;
            break;
        }
    }

    // STEP-2: Traverse through the inner matrix assuming the 0th row and 0th column as buckets.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (arr[i][j] == 0) {
                arr[0][j] = 0;
                arr[i][0] = 0;
            }
        }
    }

    // STEP-3: Update the inner matrix according the values at the corresponding buckets.
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {

            if (arr[i][0] == 0 or arr[0][j] == 0) {
                arr[i][j] = 0;
            }
        }
    }

    // STEP-4: Make updates according to the value of `zeroth_row` and `zeroth_col`.
    if (zeroth_row) {
        for (int j = 0; j < m; j++) {
            arr[0][j] = 0;
        }
    }
    if (zeroth_col) {
        for (int i = 0; i < n; i++) {
            arr[i][0] = 0;
        }
    }

    return arr;
}

int main() {

}