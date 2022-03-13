#include<bits/stdc++.h>
using namespace std;


// TC: O(log(n))

int first_occurrence(vector<int> arr, int k) {

    int first = -1;
    int low = 0, high = (int)arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            first = mid;

            // If it is not the first occ, then the first occ will lie in the left half.
            high = mid - 1;
        }
        else if (arr[mid] > k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return first;
}

int last_occurrence(vector<int> arr, int k) {

    int last = -1;
    int low = 0, high = (int)arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            last = mid;

            // If it is not the last occ, then the last occ will lie in the right half.
            low = mid + 1;
        }
        else if (arr[mid] > k) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return last;
}

int main() {
    cout << first_occurrence({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5) << endl;
    cout << last_occurrence({1, 3, 5, 5, 5, 5, 67, 123, 125}, 5) << endl;
}