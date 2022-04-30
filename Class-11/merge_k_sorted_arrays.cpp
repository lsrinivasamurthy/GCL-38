#include<bits/stdc++.h>
using namespace std;

// TC: O(n^2 * log(n))
// Aux Space: O(n)

vector<int> merge_n_sorted_arrays(vector<vector<int>> arr) {

    int n = arr.size();

    // pair<int, pair<int, int>>
    // first:           -arr[i][j]
    // second.first:    i
    // second.second:   j
    priority_queue<pair<int, pair<int, int>>> pq;

    // Push the 0-th elements of all the arrays.
    for (int i = 0; i < n; i++) {
        pq.push({-arr[i][0], {i, 0}});
    }

    vector<int> result;
    while (!pq.empty()) {

        // Pop-out the smallest element from the min-heap.
        auto current = pq.top();
        pq.pop();

        int element = -current.first;
        int i = current.second.first;
        int j = current.second.second;

        result.push_back(element);
        if (j + 1 < n) {
            pq.push({-arr[i][j + 1], {i, j + 1}});
        }
    }

    return result;
}

int main() {

    vector<int> result = merge_n_sorted_arrays({{1, 3, 5, 7},
                          {0, 2, 6, 10},
                          {4, 5, 6, 7},
                          {1, 2, 3, 4}});

    for (int i : result) {
        cout << i << " ";
    }
}