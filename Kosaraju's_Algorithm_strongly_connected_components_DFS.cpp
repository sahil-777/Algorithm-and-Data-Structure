// Strongly Connected Components : Kosaraju's Algorithm
// Def : In directed graph, Group of vertices having path between a vertex to any other vertex. 


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

vector<int>adj1[SIZE];	// Original Adjacency list
vector<int>adj2[SIZE];	//Reversed Adjacency list  (Transpose)
bool visited[SIZE];
stack<int>st;			// Stack to push a vertex after its process gets completed.
 
void dfs1(int u){		// DFS on original adjacency list
	
	visited[u]=1;
	for(auto i : adj1[u]){
		if(visited[i]==0){
			dfs1(i);
		}
	}
	st.push(u);			//After completion, Push that vertex on stack
}

void dfs2(int u){		// DFS on reversed(Tranpose) adjacency list
	
	visited[u]=1;
	cout<<u<<" ";
	for(auto i : adj2[u]){
		if(visited[i]==0){
			dfs2(i);
		}
	}
	//st.push(u);
}

int main()
{
	int N,M;
	cin>>N>>M;
	int i,j,x,y;
	 
	
	while(M--){
		cin>>x>>y;
		adj1[x].push_back(y);	//Directed Graph
	//	adj1[y].push_back(x);
	}
	
	for(i=1;i<=N;i++)
	if(visited[i]==0)		   	// Regular DFS
	dfs1(i);
	
	
	for(i=1;i<=N;i++){			//Reversing the adjacency list, reversing the edges. ( adj1 ==> adj2 )
		visited[i]=0;			// Set visited to false.
		for(j=0;j<adj1[i].size();j++){
			adj2[adj1[i][j]].push_back(i);
		}
	}
	/*	
	for(i=1;i<=N;i++){
		for(j=0;j<adj2[i].size();j++){
			cout<<adj2[i][j]<<" "; 
		}
		cout<<"\n";
	}
    */
	cout<<"Connected Components :\n";
	while(!st.empty()){		// Do this Process untill Stack gets empty.
		int s=st.top();
		st.pop();
		if(visited[s]==0)
		dfs2(s),cout<<"\n";// DFS on Reversed list with source vertex according to vertex on top of Stack.
	}
	
	return 0;
}
