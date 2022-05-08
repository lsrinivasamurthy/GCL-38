#include<bits/stdc++.h>
using namespace std;

// TC: O(n*log(n) + n*max_deadline) = O(n*(log(n) + max_deadline)).
// Aux space: O(max_deadline).

class Job {
public:
    int id;
    int deadline;
    int profit;

    Job(int id, int deadline, int profit) {
        this->id = id;
        this->deadline = deadline;
        this->profit = profit;
    }
};

bool dec_profit(Job &a, Job &b) {
    return a.profit > b.profit;
}

pair<int, int> job_sequencing(vector<Job> jobs) {

    int n = jobs.size();

    sort(jobs.begin(), jobs.end(), dec_profit);

    int max_deadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        max_deadline = max(max_deadline, jobs[i].deadline);
    }

    /*
    slots[i] corresponds to the time-slot (i -> (i + 1))
    slots[i] = false: the current slot is not yet filled.
    */
    vector<bool> slots(max_deadline, false);

    int jobs_count = 0, max_profit = 0;
    for (int i = 0; i < n; i++) {

        // Check if the current job can be accomodated in any of the available time slots.
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {

            if (slots[j] == false) {
                slots[j] = true;
                jobs_count++;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }

    return {jobs_count, max_profit};
}

int main() {

    pair<int, int> res = job_sequencing({{1, 2, 100},
                                         {2, 1, 19},
                                         {3, 2, 27},
                                         {4, 1, 25},
                                         {5, 1, 15}});

    cout << res.first << " " << res.second << endl;
}