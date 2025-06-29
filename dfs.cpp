#include<bits/stdc++.h>
using namespace std;
void dfs(char node,vector<vector<char>>&v,vector<int>&visited){
	   int index=node-'A';
	   visited[index]=1;
	   cout<<node<<" ";
	   for(auto child:v[node]){
		int i=child-'A';
		if(visited[i]==0)dfs(child,v,visited);
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
     dfs('A',v,visited);

}
/*
input
  
15 14
A B
A C
A D
A E
B F
B G
C H
D I
D J
G K
G L
I M
J N
L O

*/
