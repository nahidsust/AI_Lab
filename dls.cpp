#include <bits/stdc++.h>
using namespace std;
void dls(char node,vector<vector<char>>& v, vector<int>& visited, int limit, int depth) {
    int index = node - 'A';
    visited[index] = 1;
    cout <<node<<" ";
    if (depth >= limit) return;
    for (auto child : v[index]) {
        if (!visited[child - 'A']) {
            dls(child, v, visited, limit, depth + 1);
        }
    }
}

int main() {
    int n, e;
    cin >>n>>e;

    vector<vector<char>> v(n);

    for (int i = 0; i < e; ++i) {
        char x, y;
        cin >> x >> y;
        v[x - 'A'].push_back(y);
    }

    int depth_limit;
    cout << "Enter depth limit: ";
    cin >> depth_limit;

    cout << "DLS Traversal:\n";
    for(int i=0;i<=depth_limit;i++){
	vector<int> visited(n, 0);
    cout<<i<<" ";
    dls('A', v, visited, i, 0); 
    cout<<endl;
}
}
