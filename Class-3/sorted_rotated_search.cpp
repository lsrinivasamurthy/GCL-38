#include<bits/stdc++.h>
using namespace std;

int sorted_rotated_search(vector<int> arr, int key) {
    int n = arr.size();

    int low = 0, high = n - 1;
    while (low <= high) {

        int mid = (low + high) / 2;
        if (arr[mid] == key) {
           return mid;
        }

        // STEP-1: Check which half is sorted - left or right.
        if (arr[mid] > arr[0]) { // Left half is sorted.
            
            if (key >= arr[0] and key < arr[mid]) { // 'key' lies in the range of the sorted half.
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        else { // Right half is sorted.

            if (key > arr[mid] and key <= arr[high]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

int main() {

    cout << sorted_rotated_search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 10) << endl;
    cout << sorted_rotated_search({3, 5, 1, 2}, 6) << endl;
    cout << sorted_rotated_search({1, 2, 4, 5, 6}, 6) << endl;
    cout << sorted_rotated_search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 5) << endl;
    cout << sorted_rotated_search({5, 6, 7, 8, 9, 10, 1, 2, 3}, 3) << endl;
}