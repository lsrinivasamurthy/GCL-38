#include<bits/stdc++.h>
using namespace std;

int max_element_in_ranges(vector<int> L, vector<int> R) {

    int n = L.size();
    int max_range = R[0];
    for (int i = 1; i < n; i++) {
        max_range = max(max_range, R[i]);
    }

    vector<int> cum_freq(max_range + 2);

    for (int i = 0; i < n; i++) {
        cum_freq[L[i]]++;
        cum_freq[R[i] + 1]--;
    }

    // Convert cum_freq to a prefix-sum array so that it denotes the frequencies.
    for (int i = 1; i < cum_freq.size(); i++) {
        cum_freq[i] += cum_freq[i - 1];
    }

    // Find the smallest element with the maximum frequency.
    int result = 0;
    for (int i = 1; i < cum_freq.size(); i++) {
        if (cum_freq[i] > cum_freq[result]) {
            result = i;
        }
    }
    return result;
}

int main() {

    cout << max_element_in_ranges({2, 1, 3}, {5, 3, 9}) << endl;
    cout << max_element_in_ranges({1, 4, 3, 1}, {15, 8, 5, 4}) << endl;
    cout << max_element_in_ranges({1, 4, 3, 1}, {15, 8, 5, 3}) << endl;
    cout << max_element_in_ranges({1, 5, 6, 7}, {2, 100, 100, 100}) << endl;
}