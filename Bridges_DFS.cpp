 /*
Name:   Sahil S.Velhal
Github: Sahil-777
*/

// Bridge  : Edge if remove, increases number of connected components.

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
#include<queue>
#include<stack>
using namespace std;
#define SIZE 100001

vector<int>adj[SIZE];
bool visited[SIZE];
int parent[SIZE];
int in_time[SIZE];
int low[SIZE];

int timer =0;

void dfs_bridge(int u ){
	
	visited[u]=1;
	in_time[u]=timer;
	low[u]=timer;
	timer++;
	
	for(int child : adj[u]){
		
		if(visited[child]==0){
			parent[child] = u;			
			dfs_bridge(child);
			low[u]=min(low[child],low[u]);
			
			if(low[child]>in_time[u])
			cout<<child<<" --> "<<u<<"\n";
		}
		else if(parent[u]!=child){
			low[u]=min(low[u],in_time[child]);
		}
	}
}

int main()
{
	int N,M;
	cin>>N>>M;
	 
	int i,x,y;
	 
	for(i=1;i<=N;i++){
		visited[i]=0;
		parent[i]=-1;
	}
	
	for(i=0;i<M;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(i=1;i<=N;i++)
    if(!visited[i])
	dfs_bridge(i);
 
	return 0;
}

/*
4 6
1 3
1 4
2 1
3 2
4 2
4 3
*/
 

