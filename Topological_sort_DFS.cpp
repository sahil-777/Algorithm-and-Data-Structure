// Topological Sort 
// Def : Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices 
//		 such that for every directed edge uv, vertex u comes before v in the ordering. 
//		 Topological Sorting for a graph is not possible if graph is not DAG.

//Note : There can be multiple Topological sorts for a given DAG. 


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
 
void dfs_toposort(int u){		 
	visited[u]=1;
	for(auto i : adj[u]){
		if(visited[i]==0){
			dfs_toposort(i);
		}
	}
	st.push(u);			//Pushing Vertices on stack if its process gets completed. 			 
}
 
void print_toposort(){
	//vertices are pushed in reversed order
	cout<<"Topological sort\n"; 
	while(!st.empty()){		 
		cout<<st.top()<<" ";
		st.pop(); 
	}
	cout<<"\n";
} 

int main()
{
	int N,M;
	cin>>N>>M;
	int i,j,x,y;
	 
	while(M--){
		cin>>x>>y;
		adj[x].push_back(y); //Directed Graph
	}
	
	for(i=1;i<=N;i++)
	if(visited[i]==0)		   	 
	dfs_toposort(i);
	
	print_toposort();
	
	return 0;
}
 
