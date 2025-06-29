#include <bits/stdc++.h>
using namespace std;
bool dls(char node, char goal, vector<vector<char>>& v, vector<int>& visited, int limit, int depth) {
    int index = node - 'A';
    visited[index] = 1;
    cout << node << " ";
    if (node == goal) return true; 
    if (depth >= limit) return false;
    for (auto child : v[node]) {
        if (!visited[child - 'A']) {
            if (dls(child, goal, v, visited, limit, depth + 1)) return true;
        }
    }
    return false;
}
bool ids(char start, char goal, vector<vector<char>>& v, int maxDepth) {
    for (int limit = 0; limit <= maxDepth; ++limit) {
        cout << "\nDepth Limit: " << limit<<" ";
        vector<int> visited(100, 0); 
        if (dls(start, goal, v, visited, limit, 0)) {
            cout << "\nGoal '" << goal << "' found at depth " << limit << "!\n";
            return true;
        }
    }

    cout << "\nGoal not found within depth " << maxDepth << ".\n";
    return false;
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<vector<char>> v(n);
    for (int i = 0; i < e; ++i) {
        char x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }

    char start = 'A';
    char goal;
    int maxDepth;
    cout << "Enter goal node: ";
    cin >> goal;
    cout << "Enter max depth limit: ";
    cin >> maxDepth;

    ids(start, goal, v, maxDepth);
}
