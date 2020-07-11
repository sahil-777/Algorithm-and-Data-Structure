//Cycle detection in Directed Graph
// This method is used in CLRS book
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
#define ll   long long 

vector<int>adj[SIZE];
bool visited[SIZE];
int colour[SIZE]; 
int parent[SIZE]; //Only to print the cyle
int flag=0;
// 1 : White; 2 : Gray; 3 : Black;

// White : Yet to be processed
// Gray  : Currently Processing
// Black : Already Processed completely ( Node itself, and its neighbours)  

void print_cycle(int start){
	cout<<"Cycle => ";
	while(start!=-1){
		cout<<start<<" ";
		start=parent[start];
	}
	cout<<"\n";
}

void dfs(int u){
	visited[u]=1;
	colour[u]=2;	// Gray , in process
	for(int child : adj[u]){
		if(visited[child]==0){
			parent[child]=u;
			dfs(child);
		}
		else if(colour[child]==2){// Backedge found, edge from current vertex to GRAY vertex 
			print_cycle(u);
			flag=1;	
		}
	}
	colour[u]=3;	//Black, process completed for that vertex
}

int main()
{
	int N,M;
	cin>>N>>M;
	while(M--){
		int x,y;
		cin>>x>>y;
		adj[x].push_back(y);  // Directed Graph
		//adj[y].push_back(x);
	}
	int i;
	for(i=1;i<=N;i++){
		visited[i]=0;
		colour[i]=1; // Initially all white
		parent[i]=-1;
	} 
	
	for(i=1;i<=N;i++){
		if(visited[i]==0)
		dfs(i);
	}
	
 	if(flag==0)cout<<"No cycle present\n";	 
	return 0;
}

 
