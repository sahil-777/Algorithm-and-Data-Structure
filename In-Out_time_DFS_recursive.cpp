 /*
Name:   Sahil S.Velhal
Github: Sahil-777
*/

// In-Out Time of Nodes in Graph : DFS
// Here, Recursive DFS is best option.


/*
This is Most important technique used for :
1) Finding Bridges in a graph.
2) Finding Articulation points in a graph.
3) Flattening of Tree, so that Mo's algorithm an be applied.
4) Euler Path finding
5) Answering queries  on Tree in Constant time. 
*/

//Note : Don't use "In", "Out", "time" keywords they are inbuilt for C++ 

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
int Out_time[SIZE];
int timer =1;

void dfs(int u){
	
	In_time[u]=timer;
	timer++;
	visited[u]=1;
	for(int i : adj[u]){
		if(visited[i]==0){
			dfs(i);
		}
	}
	Out_time[u]=timer; 
	timer++;
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
	
	cout<<"In Time = > ";
	for(i=1;i<=N;i++)cout<<In_time[i]<<" ";
	cout<<"\n"; 
	
	cout<<"Out Time = > ";
	for(i=1;i<=N;i++)cout<<Out_time[i]<<" ";
	cout<<"\n";
	
    return 0;
}

/*
5 4
1 2 
3 2 
3 4 
5 4
1
*/
