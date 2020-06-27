/*
Name:   Sahil S.Velhal
Github: Sahil-777
*/

// DFS : Depth First Search - Graph Traversal

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

void dfs(int s){
	
	visited[s]=1;
	st.push(s);
	int u,i;
	while(!st.empty()){
		u=st.top();
		cout<<u<<" ";
		st.pop();
		for(i=0;i<adj[u].size();i++){
			if(visited[adj[u][i]]==0){
				visited[adj[u][i]]=1;
				st.push(adj[u][i]);
			}
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
	
	int s;
	cin>>s;
	dfs(s);
	 
    return 0;
}
