// Kahns's Algorithm for Topological sort :

//STEP 1: Push (Enqueue) nodes having in-degree == 0 in Queue.
//STEP 2: Remove Edges associated with that node.
//STEP 3: Perform steps 1 & 2, until Queue gets empty.

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
int in_degree[SIZE];			 
queue<int>q;
vector<int>answer;

void kahns_topo(int N){
	
	for(int i=1;i<=N;i++)
		if(in_degree[i]==0)			//Pushing all nodes having in-degree == 0
			q.push(i);
			
	while(!q.empty()){
		int u=q.front();
		answer.push_back(u);		//Adding node in Final answer, as Queue has nodes having in-degree == 0
		q.pop();
		for(int child:adj[u]){
			in_degree[child]--;		//Removing Edges associated with that node 
			if(in_degree[child]==0)	//Pushing node in Queue having in-degree == 0
				q.push(child);
		}
	}
	
	if(answer.size()!=N)			//It means graph is not DAG,it has Cycle.
	cout<<"Cycle Present : Topological Sort Not Possible\n";
	else
	for(int node:answer)			//Printing Final Answer i.e. Topological sort
	cout<<node<<" ";		
	cout<<"\n";
} 
 
int main()
{
	int N,M;
	cin>>N>>M;
	
	int i,j,x,y;
	 
	while(M--){
		cin>>x>>y;
		adj[x].push_back(y);		//Directed graph
		in_degree[y]++;				//Calculating in-degree of every node   
	}
	
	kahns_topo(N);
	
	return 0;
}
 
