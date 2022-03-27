#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux space: O(1)

bool is_alpha_numeric(char ch) {

    return ((ch >= 'a' and ch <= 'z') or 
            (ch >= 'A' and ch <= 'Z') or 
            (ch >= '0' and ch <= '9'));

    // if (ch >= 'a' and ch <= 'z') {
    //     return true;
    // }
    // if (ch >= 'A' and ch <= 'Z') {
    //     return true;
    // }
    // if (ch >= '0' and ch <= '9') {
    //     return true;
    // }

    // return false;
}

bool are_equal(char ch1, char ch2) {

    // If ch1 == ch2 => return true
    // If ch1 is uppercase and ch2 is lowercase => convert ch1 to uppercase and compare with ch2
    // If ch1 is lowercase and ch2 is uppercase => convert ch1 to lowercase and compare with ch2 

    return ((ch1 == ch2) or
            (ch1 - 'A' + 'a' == ch2) or
            (ch1 - 'a' + 'A' == ch2));

    // if (ch1 == ch2) {
    //     return true;
    // }
    // if (ch1 - 'A' + 'a' == ch2) {
    //     return true;
    // }
    // if (ch1 - 'a' + 'A' == ch2) {
    //     return true;
    // }
    // return false;
}


bool check_palindrome_variation(string s) {

    int n = s.length();

    int i = 0, j = n - 1;

    while (i < j) {

        if (!is_alpha_numeric(s[i])) {
            i++;
        }
        else if (!is_alpha_numeric(s[j])) {
            j--;
        }
        else {
            // Check if s[i] and s[j] are equal. Also, make sure that the cases are ignored.
            if (are_equal(s[i], s[j])) {
                i++;
                j--;
            }
            else {
                return false;
            }
        }
    }
    return true;
}

int main() {

    cout << check_palindrome_variation("A man, a plan, a canal: Panama") << endl;
    cout << check_palindrome_variation("race a car") << endl;
}