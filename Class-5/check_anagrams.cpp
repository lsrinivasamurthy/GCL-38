#include<bits/stdc++.h>
using namespace std;

// TC: O(n)
// Aux space: O(1)
// Space complexity: O(n)

bool check_anagrams(string s1, string s2) {

    int n = s1.length();
    if ((int)s2.length() != n) {
        return false;
    }

    // frequency of 'a' will be stored at 0th index
    // 'b' at 1st index
    // 'c' at 2nd index
    // ...
    // 'z' at 25th index

    vector<int> char_freq(26, 0);

    // Storing the frequency of each character in both the strings.
    for (int i = 0; i < n; i++) {
        char_freq[s1[i] - 'a']++;
        char_freq[s2[i] - 'a']--;
    }
    
    // Comparing the frequency of each character in both the strings.
    for (int i = 0; i < 26; i++) {
        if (char_freq[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {

    cout << check_anagrams("geeksforgeeks", "forgeeksgeeks") << endl;
    cout << check_anagrams("allergy", "allergic") << endl;
}
