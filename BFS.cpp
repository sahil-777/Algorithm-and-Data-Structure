//BFS : Breadth First Search
//This is graph traversal algorithm which traverses graph level wise.
//Time Complexity: O(V+E);


#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define SIZE 100001
#define INF  1e9
#define ll   long long  
#define mod  1e9+7

vector<int>adj[SIZE];
bool visited[SIZE];
queue<int>q;

void bfs(int s){

    visited[s]=true;
    q.push(s);
    
    while(!q.empty()){
        int u=q.front();
        cout<<u<<" ";
        q.pop();
        
        for(int child:adj[u]){
            if(!visited[child]){
                visited[child]=true;
                q.push(child);
            }
        }
    }
}

 
int main(){

    int N,M;
    cin>>N>>M;

    while(M--){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);//For Undirectinal graph
    }

    for(int i=1;i<=N;i++)//Initial values 
        visited[i]=false;

    for(int i=1;i<=N;i++)
        if(!visited[i])
            bfs(i),cout<<"\n";

    return 0; 
} 
