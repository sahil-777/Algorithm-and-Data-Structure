 /*
Name:   Sahil S.Velhal
Github: Sahil-777
*/

// Articulation Point  : Node if remove, increases number of connected components.

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
bool AP[SIZE];  //To store whether Node is Articulation point or not 
int ch=0;

int timer =0;

void dfs_AP( int u ){
	
	visited[u] = 1;
	in_time[u] = timer;
	low[u] = timer;
	timer++;
	ch=0; //Count of children ,to check for node.
	
	for(int child : adj[u]){
		
		if(visited[child]==0){
			ch++;
			parent[child] = u;
			dfs_AP(child);
			low[u]=min(low[child],low[u]);
			
			if((parent[u]==-1)and(ch>1))//root having more than 1 child is Articulation Point 
			AP[u]=true;
			
			if((parent[u]!=-1)and(low[child]>=in_time[u]))
			AP[u]=true;
			 
		}
		else if(parent[u]!=child){ //shows backedge
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
		AP[i]=false;
	}
	
	int s=1;
	dfs_AP(s);
	
	for(i=1;i<=N;i++){
		if(AP[i]==true)
		cout<<i<<" ";
	}
	
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

