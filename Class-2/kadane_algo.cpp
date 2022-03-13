#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux space: O(n)
int max_sum_of_any_subarray(vector<int> arr) {
    int n = arr.size();

    vector<int> meh(n);
    meh[0] = arr[0];
    int result = meh[0];

    for (int i = 1; i < n; i++) {
        if (meh[i - 1] > 0) {
            meh[i] = meh[i - 1] + arr[i];
        }
        else {
            meh[i] = arr[i];
        }

        result = max(result, meh[i]);
    }

    return result;
}

// TC: O(n)
// Aux space: O(1)
int max_sum_of_any_subarray_space_opt(vector<int> arr) {
    int n = arr.size();

    int previous_max = arr[0];
    int result = arr[0];

    // meh[i - 1] == previous_max
    // meh[i] == current_max
    for (int i = 1; i < n; i++) {
        int current_max;
        if (previous_max > 0) {
            current_max = previous_max + arr[i];
        }
        else {
            current_max = arr[i];
        }

        result = max(result, current_max);
        previous_max = current_max;
    }

    return result;
}

int main() {

    cout << max_sum_of_any_subarray({-5, 1, 3, -7, 5, 2}) << endl;
    cout << max_sum_of_any_subarray({1, 2, 3, -2, 5}) << endl;
    cout << max_sum_of_any_subarray({-1, -2, -3, -4}) << endl;

    cout << max_sum_of_any_subarray_space_opt({-5, 1, 3, -7, 5, 2}) << endl;
    cout << max_sum_of_any_subarray_space_opt({1, 2, 3, -2, 5}) << endl;
    cout << max_sum_of_any_subarray_space_opt({-1, -2, -3, -4}) << endl;
}