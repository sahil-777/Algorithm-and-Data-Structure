//Dijkstra's Algorithm:
//It is Single Source Shortest Path Algorithm for weighted graph. It is greedy algorithm.

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
#define INF  1e9					//Value of Infinity

vector<pair<int,int>>adj[SIZE];		//Adjacency list of pair to store => [ u,(v,w) ]	 
set< pair<int,int> >sp;				//pair of ( Weight, vertex )
int parent[SIZE];					//To print path
int cost[SIZE];						//To count minimum cost

void dijkstra(int s){				//s=> Source
	sp.insert(make_pair(0,s));		//Inserting source in set
	cost[s]=0;						//Cost to reach starting vertex is 0
	
	while(!sp.empty()){
		pair<int,int>temp=*sp.begin();		//choose edge having least weight 
		sp.erase(sp.begin());				//erase after choosing
		int u=temp.second;					//staring point of edge
		
		for(pair<int,int> child:adj[u]){
			int v=child.first;				//end point of egde
			int w=child.second;				//weight associated with that edge
			
			if( cost[u] + w <cost[v] ){
				if(cost[v]!=INF)			//we found an edge which was previously discovered,but is now useless
				sp.erase(sp.find(make_pair(cost[v],v)));//so erase it from set
				
				parent[v]=u;				//assign parent
				cost[v]=cost[u]+w;			//update cost
				sp.insert(make_pair(cost[v],v));//insert new edge	
			}
		}
	}
}

void print_path(int dest){					//printing path
	cout<<"Path: ";
	while(dest!=-1){
		cout<<dest<<" ";
		dest=parent[dest];
	}
	cout<<"\n";
}
 
int main()
{
	int N,M;
	cin>>N>>M;
	
	int i,j,x,y,w;
	 
	while(M--){
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(y,w));	//Directed graph, w=> weight
//		adj[y].push_back(make_pair(x,w));
	}
	
	for(i=1;i<=N;i++){						//Setting initial values
		cost[i]= INF;						//Setting initial cost to Infinity  
		parent[i]= -1;
	}
	
	int s;
	cout<<"Enter Source vertex: ";
	cin>>s;
	dijkstra(s);
	
	cout<<"Cost to reach vertex from given source: ";
	for(i=1;i<=N;i++)
	cout<<cost[i]<<" ";
	
	cout<<"\nEnter Destination for Path: ";
	int dest;
	cin>>dest;
	print_path(dest);
	
	return 0;
}
 
