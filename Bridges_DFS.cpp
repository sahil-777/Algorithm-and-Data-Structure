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
stack<int>st;
int In_time[SIZE];
int low[SIZE];
int timer =1;

void dfs(int u,int parent){
	
	visited[u]=1;
	//cout<<u<<"\n";
	In_time[u]=timer;
	low[u]=timer;
	timer++;
	
	for(int i : adj[u]){
		
		if(i==parent)
			continue;
		
		if(visited[i]==0){
			
			dfs(i,u);
			low[u]=min(low[i],low[u]);
			
			if(low[i]>In_time[u])
			cout<<i<<" --> "<<u<<"\n";
		}
		else{
			low[u]=min(low[i],In_time[u]);
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
	
	int s=1;
	dfs(s,-1);
	
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
