//Floyd-Warshall Algorithm:
//This algorithm is used to find shortest path between any pair of vertices.
//Time Complexity : O(V^3), where V: No. of Vertices.

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<iterator>
#include<math.h>
#include<queue>
#include<map>
using namespace std;
#define SIZE 1001 //Siz of matrix will be size*size
#define INF  1e9
#define ll   long long  

int cost[SIZE][SIZE];// To store Cost from a vertex to another vertex
int adjmatrix[SIZE][SIZE];// To store edges and thier weights, adjlist is not nrecessary. 

void floyd_warshall(int N){
    // we know,
    // Shortestpath(i,j)= Shortestpath(i,k) + Shortestpath(k,j);
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                
                if(cost[i][k] + cost[k][j] < cost[i][j])  
                    cost[i][j] = cost[i][k]+cost[k][j];
            
            }
        }
    }
}

void print_cost(int N){
    //To print the minimum cost from one node to another 
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(cost[i][j]==INF)
            cout<<"INF  ";
            else
            cout<<cost[i][j]<<"    ";
        }
        cout<<"\n";
    }

}

int main(){
     int N,M;
     cin>>N>>M;

     //Filling initial values
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i==j)
                adjmatrix[i][j]=0,cost[i][j]=0;//Cost to travel from a node to same node is zero
            else
                adjmatrix[i][j]=INF,cost[i][j]=INF;//initially infinity
        }
    }
     
    while(M--){
        int x,y,w;
        cin>>x>>y>>w;
        adjmatrix[x][y]=w;//This matrix can be converted to adjlist, vice versa
        cost[x][y]=w;
    }
    
    floyd_warshall(N);//Don't need to pass source vertex, as it finds minimum cost for all pairs 
    
    print_cost(N);
    
    return 0; 
} 
