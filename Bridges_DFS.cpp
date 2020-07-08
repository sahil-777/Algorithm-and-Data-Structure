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

int timer =1;

void dfs_Bridge(int u ){
	
	visited[u]=1;
	in_time[u]=timer;
	low[u]=timer;
	timer++;
	
	for(int child : adj[u]){
		
		if(visited[child]==0){
			parent[child] = u;			
			dfs_Bridge(child);
			low[u]=min(low[child],low[u]);
			
			if(low[child]>in_time[u])
			cout<<child<<" --> "<<u<<"\n";
		}
		else if(parent[u]!=child){
			low[u]=min(low[child],in_time[u]);
		}
	}
}

int main()
{
	int N,M;
	cin>>N>>M;
	 
	int i,x,y;
	 
	for(i=0;i<M;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	
	for(i=1;i<=N;i++){
		visited[i]=0;
		parent[i]=-1;
		low[i]=INT32_MAX;
	}
	
	int s=1;
	dfs_Bridge(s);
	
	return 0;
}

/*
6 6
1 2
1 3
2 3
3 4
4 5
4 6
*/ 
