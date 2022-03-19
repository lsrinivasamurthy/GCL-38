#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux space: O(n)
bool check_zero_sum_subarray(vector<int> arr) {
    
    unordered_map<int, bool> pref_sum;
    
    int current_sum = 0;

    pref_sum[0] = true;
    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];

        // If the `current_sum` has previously been inserted in the hashmap.
        if (pref_sum.find(current_sum) != pref_sum.end()) {
            return true;
        }

        pref_sum[current_sum] = true;
    }

    return false;
}

int count_zero_sum_subarray(vector<int> arr) {

    unordered_map<int, int> pref_sum_freq;

    int current_sum = 0;
    pref_sum_freq[0] = 1;

    int result = 0;

    for (int i = 0; i < arr.size(); i++) {
        current_sum += arr[i];
        result += pref_sum_freq[current_sum];

        pref_sum_freq[current_sum]++;
    }

    return result;
}

int main() {

    cout << check_zero_sum_subarray({4, 2, -3, 1, 6}) << endl;
    cout << check_zero_sum_subarray({4, 2, 0, 1, 6}) << endl;
    cout << check_zero_sum_subarray({1, -1, 2, 3, 4}) << endl;
    cout << check_zero_sum_subarray({0, 1, 2, 3}) << endl;

    cout << check_zero_sum_subarray({-2, 1, 2, 3}) << endl;
    cout << check_zero_sum_subarray({2, 1, 2, 3}) << endl;

    cout << count_zero_sum_subarray({1, 2, -2, 2, -2}) << endl;
    cout << count_zero_sum_subarray({0, 0, 0}) << endl;
}