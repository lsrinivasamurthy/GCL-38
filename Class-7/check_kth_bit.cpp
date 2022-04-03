#include<bits/stdc++.h>
using namespace std;

bool check_kth_bit(int n, int k) {

    int mask = (1 << k);
    if ((n & mask) != 0) {
        return true;
    }
    return false;
}

int main() {
    cout << check_kth_bit(10, 0) << endl;
    cout << check_kth_bit(10, 1) << endl;
    cout << check_kth_bit(10, 2) << endl;
    cout << check_kth_bit(10, 3) << endl;
}