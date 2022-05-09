#include<bits/stdc++.h>
using namespace std;

// TC: O(n * log(n))
// Aux space: O(1)

int get_max_task_count(vector<int> times, int total_time) {

    sort(times.begin(), times.end());

    for (int i = 0; i < times.size(); i++) {
        if (times[i] <= total_time) {
            total_time -= times[i];
        }
        else {
            return i;
        }
    }

    return times.size();
}

int main() {

    cout << get_max_task_count({4, 2, 1, 2, 5}, 8) << endl;
    cout << get_max_task_count({3, 2, 1, 2, 5}, 8) << endl;
}
