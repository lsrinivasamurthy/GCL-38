#include<bits/stdc++.h>
using namespace std;

vector<string> generate_binary(int n) {

    vector<string> result;
    queue<string> q;

    int push_count = 1;
    q.push("1");

    while (result.size() != n) {

        string current = q.front();
        q.pop();

        result.push_back(current);

        if (push_count < n) {
            q.push(current + "0");
            q.push(current + "1");
        }
        push_count += 2;
    }

    cout << q.size() << endl;
    
    return result;
}

int main() {

    vector<string> result = generate_binary(11);
    for (auto i : result) {
        cout << i << endl;
    }
}
