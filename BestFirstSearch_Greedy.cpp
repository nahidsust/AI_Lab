#include <bits/stdc++.h>
using namespace std;

vector<int> heuristics;
vector<int> vis(100), par(100, -1);
vector<int> adj[100];
  //greedy bfs
bool best_first_search(int start, int goal) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
    pq.push({heuristics[start], start});
    vis[start] = 1;
    par[start] = -1;

    while (!pq.empty()) {
        auto [h, node] = pq.top(); pq.pop();

        if (node == goal) return true;

        for (int child : adj[node]) {
            if (!vis[child]) {
                vis[child] = 1;
                par[child] = node;
                pq.push({heuristics[child], child});
            }
        }
    }
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    int start, goal;
    cin >> start >> goal;

    heuristics.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> heuristics[i];
    }

    while (e--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // if undirected
    }

    if (best_first_search(start, goal)) {
        // print path
        vector<int> path;
        for (int at = goal; at != -1; at = par[at]) {
            path.push_back(at);
        }
        reverse(path.begin(), path.end());
        cout << "Path: ";
        for (int node : path) cout << node << " ";
        cout << '\n';
    } else {
        cout << "No path found.\n";
    }

    return 0;
}
