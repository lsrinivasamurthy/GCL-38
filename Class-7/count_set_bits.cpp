#include<bits/stdc++.h>
using namespace std;

// TC: O(number of bits)
int count_set_bits(int n) {
    int cnt = 0;

    while (n != 0) {
        // If the rightmost bit is set, increment cnt.
        if ((n & 1) != 0) {
            cnt++;
        }

        // Discarding the rightmost bit.
        n = (n >> 1);
    }
    return cnt;
}

// TC: O(number of set bits)
int count_set_bits_opt(int n) {
    int cnt = 0;

    while (n != 0) {
        n = (n & (n - 1));
        cnt++;
    }
    return cnt;
}

int main() {

    cout << count_set_bits(10) << endl;
    cout << count_set_bits(7) << endl;

    cout << count_set_bits_opt(10) << endl;
    cout << count_set_bits_opt(7) << endl;
}