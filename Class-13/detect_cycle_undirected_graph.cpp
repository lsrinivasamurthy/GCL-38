#include<bits/stdc++.h>
using namespace std;

// TC: O(V + E)
// Aux Space: O(V)

bool detect_cycle_undirected_graph_util(vector<vector<int>> &adj, int current, int parent, vector<bool> &vis) {

    vis[current] = true;

    for (int j : adj[current]) {
        if (vis[j] and j != parent) {
            return true;
        }

        // At this stage, we will return ONLY IF the component contains a cycle.
        if (!vis[j] and detect_cycle_undirected_graph_util(adj, j, current, vis)) {
            return true;
        }
    }

    return false;
}

bool detect_cycle_undirected_graph(vector<vector<int>> adj) {

    int n = adj.size();
    vector<bool> vis(n, false);

    for (int i = 0; i < n; i++) {
        if (!vis[i] and detect_cycle_undirected_graph_util(adj, i, -1, vis)) {
            return true;
        }
    }

    return false;    
}


int main() {

    cout << detect_cycle_undirected_graph({{1},
                                           {0, 2},
                                           {1, 3},
                                           {2, 4},
                                           {3}});

    cout << endl;

    cout << detect_cycle_undirected_graph({{1},
                                           {0, 2, 4},
                                           {1, 3},
                                           {2, 4},
                                           {1, 3}});

    cout << endl;

    cout << detect_cycle_undirected_graph({{0}});
}