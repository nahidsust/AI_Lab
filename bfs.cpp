#include<bits/stdc++.h>
using namespace std;
void bfs(char startNode,vector<vector<char>>&v,vector<int>&visited) {
    queue<char>q;
    q.push(startNode);
    visited[startNode -'A'] =1;

    while(!q.empty()){
        char node=q.front();
        q.pop();
        cout <<node<<" ";

        for(auto child:v[node]){
            if (!visited[child-'A']){
                visited[child-'A']=1;
                q.push(child);
            }
        }
    }
}

int main(){
    int n,e;
    cin>>n>>e;
    vector<vector<char>>v(n);
    vector<int>visited(n,0);

    while(e--){
        char x,y;
        cin>>x>>y;
        v[x].push_back(y); 
    }

    bfs('A',v,visited);  
}
