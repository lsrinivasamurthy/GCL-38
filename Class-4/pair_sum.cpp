#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux space: O(1)
// Space complexity: O(n)
bool check_pair_with_given_sum(vector<int> arr, int target) {

    int n = arr.size();
    int i = 0, j = n - 1;

    while (i < j) {

        if (arr[i] + arr[j] == target) {
            return true;
        }
        if (arr[i] + arr[j] > target) {
            j--;
        }
        else {
            i++;
        }
    }

    return false;    
}

int main() {

    cout << check_pair_with_given_sum({1, 2, 5, 6, 10}, 8) << endl;
    cout << check_pair_with_given_sum({1, 2, 5, 6, 10}, 9) << endl;
}