#include<bits/stdc++.h>
using namespace std;

class Queue {
    stack<int> s1;
    stack<int> s2;

public:

    // TC: O(1)
    void queue_push(int ele) {
        s1.push(ele);
    }

    // TC: O(n)
    // Pop the front element of the queue and return it.
    int queue_pop() {

        if (s1.empty()) {
            cout << "Performing pop on an empty queue\n";
            return -1;
        }

        // Empty s1 to s2.
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        int answer = s2.top();
        s2.pop();

        // Empty s2 to s1.
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        return answer;
    }
};

int main() {

    Queue q;
    q.queue_push(1);
    q.queue_push(2);
    q.queue_push(3);

    cout << q.queue_pop() << endl;

    q.queue_push(4);
    q.queue_push(5);

    cout << q.queue_pop() << endl;
    cout << q.queue_pop() << endl;
    cout << q.queue_pop() << endl;
    cout << q.queue_pop() << endl;
    cout << q.queue_pop() << endl;

    // HW: Try implementing stack using two queues.
}