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
int flag=0;

void dfs_undirected_cycle_detection(int u){
	visited[u]=1;
	
	for(int child :adj[u]){
		if(visited[child]==0){
			parent[child]=u;
			dfs_undirected_cycle_detection(child);
		}
		else if(parent[u]!=child)
		flag=1;
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
	dfs_undirected_cycle_detection(i);
	
	if(flag==1)
	cout<<"Cycle present\n";
	else
	cout<<"No cycle\n";
	 
	return 0;
}

 
