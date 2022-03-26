#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux space: O(n)
// Space complexity: O(n)
vector<int> product_except_self(vector<int> arr) {

    int n = arr.size();

    vector<int> left_prod(n);
    vector<int> right_prod(n);

    left_prod[0] = 1;
    for (int i = 1; i < n; i++) {
        left_prod[i] = left_prod[i - 1] * arr[i - 1];
    }

    right_prod[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        right_prod[i] = right_prod[i + 1] * arr[i + 1];
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++) {
        answer[i] = left_prod[i] * right_prod[i];
    }
    return answer;
}

int main() {

    vector<int> answer = product_except_self({4, 5, 1, 8, 2});
    for (int i : answer) {
        cout << i << " ";
    }
    cout << endl;

    answer = product_except_self({1, 2, 0, 4});
    for (int i : answer) {
        cout << i << " ";
    }
    cout << endl;

    answer = product_except_self({0, 2, 0, 4});
    for (int i : answer) {
        cout << i << " ";
    }
    cout << endl;
}