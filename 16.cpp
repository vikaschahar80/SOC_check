#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& on_stack, vector<int>& topo_order, bool& has_cycle) {
    visited[node] = true;
    on_stack[node] = true;

    for (int neighbor : adj[node]) {
        if (has_cycle) return; 
        if (!visited[neighbor]) {
            solve(neighbor, adj, visited, on_stack, topo_order, has_cycle);
        } else if (on_stack[neighbor]) {
            has_cycle = true;
            return;
        }
    }

    on_stack[node] = false;
    topo_order.push_back(node);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<bool> visited(n + 1, false);
    vector<bool> on_stack(n + 1, false);
    vector<int> topo_order;
    bool has_cycle = false;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            solve(i, adj, visited, on_stack, topo_order, has_cycle);
        }
    }

    if (has_cycle) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        reverse(topo_order.begin(), topo_order.end());
        for (int course : topo_order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
