#include<bits/stdc++.h>
using namespace std;


// SC = input space + aux space + output space.

// TC: O(n + m)
// Aux space: O(1)
// Space complexity: O(n * m)
bool matrix_search(vector<vector<int>> arr, int x) {

    int n = arr.size();
    int m = arr[0].size();

    int i = 0, j = m - 1;
    while(i < n and j >= 0) {

        if (arr[i][j] == x) {
            return true;
        }
        if (arr[i][j] > x) {
            j--;
        }
        else {
            i++;
        }
    }

    return false;
}

int main() {

    cout << matrix_search({{3, 30, 38}, {36, 43, 60}, {40, 51, 69}}, 62) << endl;
    cout << matrix_search({{3, 30, 38}, {36, 43, 60}, {40, 51, 69}}, 40) << endl;
}