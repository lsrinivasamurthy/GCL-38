#include<bits/stdc++.h>
using namespace std;


// TC: O(n)
// Aux Space: O(n)
bool check_balanced(string s) {

    stack<char> helper;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{' or s[i] == '(' or s[i] == '[') {
            helper.push(s[i]);
        }
        else {
            // Check whether the top of the stack and the current closing bracket are corresponding
            // to each other or not.

            if (helper.empty()) {
                return false;
            }
            if (s[i] == '}' and helper.top() != '{') {
                return false;
            }
            if (s[i] == ')' and helper.top() != '(') {
                return false;
            }
            if (s[i] == ']' and helper.top() != '[') {
                return false;
            }

            helper.pop();
        }
    }

    // if (helper.empty()) {
    //     return true;
    // }
    // return false;

    return helper.empty();
}

int main() {

    cout << check_balanced("{([])}") << endl;
    cout << check_balanced("([]") << endl;
    cout << check_balanced("([]))") << endl;
    cout << check_balanced("([)]") << endl;
}