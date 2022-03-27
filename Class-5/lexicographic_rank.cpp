#include<bits/stdc++.h>
using namespace std;

vector<int> fact;

int mod = 1000003;
void pre(int n) {

    fact = vector<int> (n);
    fact[0] = 1;
    fact[1] = 1;

    for (int i = 2; i < n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

// TC: O(n^2)
// Aux space: O(n)
int lexicographic_rank(string s) {

    int n = s.length();
    pre(n);

    string s_sorted = s;
    sort(s_sorted.begin(), s_sorted.end());

    int result = 0;
    for (int i = 0; i < n; i++) {

        int smaller_count = 0;

        // Number of smaller characters than s[i] == number of non-hash characters occurring before
        // s[i] in the string s_sorted.
        for (int j = 0; j < n; j++) {
            if (s_sorted[j] == s[i]) {
                s_sorted[j] = '#';
                break;
            }

            if (s_sorted[j] != '#') {
                smaller_count++;
            }
        }

        result = (result + (smaller_count * fact[n - i - 1]) % mod) % mod;
    }

    return (result + 1) % mod;
}

int main() {

    cout << lexicographic_rank("acb") << endl;
    cout << lexicographic_rank("view") << endl;
    cout << lexicographic_rank("veiw") << endl;
}