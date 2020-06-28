/*
Name:   Sahil S.Velhal
Github: Sahil-777
*/

// Bipartite graph test with DFS
// 2-colouring problem
// It handles only strongly connected graph.

#include<iostream>
#include<set>
#include<vector>
#include<stack>
using namespace std;
#define SIZE 100001

vector<int>adj[SIZE];
bool visited[SIZE];
stack<int>st;
int colour[SIZE];

bool dfs(int s){
    st.push(s);
    visited[s]=1;
    int i,u;
    while(!st.empty()){
        u=st.top();
        st.pop();
        //cout<<u<<" ";
        for(i=0;i<adj[u].size();i++){
            if(visited[adj[u][i]]==0){
                visited[adj[u][i]]=1;
                st.push(adj[u][i]);
                colour[adj[u][i]]=colour[u]^1;
            }
            else if(colour[adj[u][i]]==colour[u]){
            	return false;
			}
        }
    }
    return true;
}


int main(){
    
    for(int i=1;i<=SIZE;i++){
        visited[i]=0;
        colour[i]=0;
    }
    
    int N,M;
    cin>>N>>M;
    int i,j,x,y;
    for(i=0;i<M;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
	
	 
    cout<<dfs(1)<<"\n";// True if Bipartite, otherwise false
	 
	return 0;
}
