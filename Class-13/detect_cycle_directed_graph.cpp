#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// Aux space: O(V)

bool detect_cycle_directed_graph_helper(vector<vector<int>> &adj, int current, vector<bool> &vis, vector<bool> &rec_stack) {

    vis[current] = true;
    rec_stack[current] = true;

    for (int j : adj[current]) {
        if (rec_stack[j]) {
            return true;
        }
        if (detect_cycle_directed_graph_helper(adj, j, vis, rec_stack)) {
            return true;
        }
    }

    rec_stack[current] = false;
    return false;
}

bool detect_cycle_directed_graph(vector<vector<int>> adj) {

    int n = adj.size();
    vector<bool> vis(n, false);
    vector<bool> rec_stack(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i] and detect_cycle_directed_graph_helper(adj, i, vis, rec_stack)) {
            return true;
        }
    }
    return false;
}


int main() {

    cout << detect_cycle_directed_graph({{},
                                         {0, 2},
                                         {3},
                                         {1}});

    cout << endl;

    cout << detect_cycle_directed_graph({{1},
                                         {2, 3},
                                         {3},
                                         {}});
}