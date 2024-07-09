#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void find_cycle(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& in_stack, vector<int>& parent, int& start, int& end) {
    visited[node] = true;
    in_stack[node] = true;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            parent[neighbor] = node;
            find_cycle(neighbor, adj, visited, in_stack, parent, start, end);
            if (start != -1) 
              return; 
        } else if (in_stack[neighbor]) {
            start = neighbor;
            end = node;
            return;
        }
    }

    in_stack[node] = false;
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
    vector<bool> in_stack(n + 1, false);
    vector<int> parent(n + 1, -1);
    int start = -1, end = -1;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            find_cycle(i, adj, visited, in_stack, parent, start, end);
            if (start != -1) 
              break; 
        }
    }

    if (start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(start);
        for (int v = end; v != start; v = parent[v]) {
            cycle.push_back(v);
        }
        cycle.push_back(start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
