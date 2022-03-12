
/*
TC: O(n + m)
Aux Space: O(1)
Space Complexity: O(n + m)
*/

for (int i = 0; i < A.size(); i++) {
    cout << A[i] << endl;
}
for (int i = 0; i < B.size(); i++) {
    cout << B[i] << endl;
}

// ---------------------------------------------------

/*
TC: O(n * m)
Aux Space: O(1)
Space Complexity: O(n + m)
*/

for (int i = 0; i < A.size(); i++) {
    for (int j = 0; j < B.size(); j++) {
        cout << A[i] + B[j] << endl;
    }
}

// ---------------------------------------------------

/*
TC: O(n^2)
Aux Space: O(1)
Space Complexity: O(1)
*/

void func(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << i + j << endl;
        }
    }
}

// ---------------------------------------------------

/*
TC: O(m * n^2)
Aux Space: O(1)
Space Complexity: O(m)
*/

// s.length() == `m`
void func(int n, string s) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << s << endl;
        }
    }
}

