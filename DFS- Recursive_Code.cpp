 /*
Name:   Sahil S.Velhal
Github: Sahil-777
*/

// Recursive DFS

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
 
void dfs(int u){
	
	visited[u]=1;
	cout<<u<<" ";
	for(auto i : adj[u]){
		if(visited[i]==0){
			dfs(i);
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
