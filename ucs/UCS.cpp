#include<bits/stdc++.h>
using namespace std;
bool ucs(vector<vector<pair<int,int>>>&vp,int start,int goal,vector<int>&vis,vector<int>&dis){
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
                pq.push({0,start});
                dis[start]=0;
                while(!pq.empty()){
		auto [h,currentNode]=pq.top();
		pq.pop();
		 if(vis[currentNode]) continue;
		 if(currentNode==goal)return true; //for dijkstra remove this like and rest of code unchanged
		vis[currentNode]=1;
		
		for(auto [child,W]:vp[currentNode]){
			if(vis[child]==0 && dis[currentNode]+W<dis[child]){
					
				dis[child]=dis[currentNode]+W;
				pq.push({dis[child],child})  ;
			}
		}
		
                }
	return false;
}
int main(){
int n,e;
cin>>n>>e;
vector<vector<pair<int,int>>>vp(n);
   while(e--){
	int x,y,w;
	cin>>x>>y>>w;
	vp[x].push_back({y,w});
	vp[y].push_back({x,w});
	
   }
   vector<int>vis(n,0);
   vector<int>dis(n,INT_MAX) ;
   int start,goal;
   cin>>start>>goal;
   if(ucs(vp, start,goal,vis,dis)){
	 cout<<"YES";
   }
   else cout<<"NO";
   for(int i=0;i<n;i++)cout<<i<<" "<<dis[i]<<endl;

}
/*
6 8
0 1 3
0 2 2
2 4 3
1 4 2
1 3 1
3 4 4
3 5 7
4 5 5
*/
