#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>v[1000];
vector<int>heuristics(100,0);
int vis[100],par[100],dis[100];
bool a_star(int source,int goal){
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
      par[source]=-1;
      dis[source]=0;
      pq.push({heuristics[source],source});
      while(!pq.empty()){
		
	 auto top=pq.top();
	 pq.pop();
	 int node=top.second;
      if(vis[node])continue;
      if(node==goal)return true;
	 vis[node]=1;
	 for(auto val:v[node]){
		    int child=val.first;
		    int value=val.second; 
		    
		    if(dis[child]>dis[node]+value){
				
				dis[child]=dis[node]+value;
			pq.push({(dis[child]+heuristics[child]),child});
			par[child]=node;
			
		    }
	 }
      }
     return false; 
      
}
int main(){
int n,e;
cin>>n>>e;
for(int i=0;i<n;i++){
	cin>>heuristics[i];
	dis[i]=1e7;
}
while(e--){
	int x,y,w;
	cin>>x>>y>>w;
	v[x].push_back({y,w});
	
}
int source,goal;
cin>>source>>goal;
if(a_star(source,goal))
for(int i=0;i<n;i++)cout<<i<<" "<<par[i]<<endl;
else cout<<"Not found"<<endl;
}

/*
7 9
5 6 4 3 3 1 0
0 1 1
0 2 4
1 2 2
1 3 3
3 4 2
4 5 1
3 5 4
2 6 5
6 5 3
*/
