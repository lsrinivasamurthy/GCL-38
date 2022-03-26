#include<bits/stdc++.h>
using namespace std;


// TC: O(n^2)
bool triplet_sum(vector<int> arr, int target) {

    sort(arr.begin(), arr.end());
    int n = arr.size();
    
    for (int i = 0; i < n - 2; i++) {

        // Two-pointer approach to check if pair with sum = (target - arr[i]) is present in
        // arr[i + 1] .... arr[n - 1]
        int s = i + 1, e = n - 1;
        while (s < e) {
            if (arr[s] + arr[e] == target - arr[i]) {
                return true;
            }
            if (arr[s] + arr[e] > target - arr[i]) {
                e--;
            }
            else {
                s++;
            }
        }
    }

    return false;
}

int main() {

    cout << triplet_sum({1, 4, 45, 6, 10, 8}, 13) << endl;
    cout << triplet_sum({1, 4, 45, 6, 10, 8}, 30) << endl;
}