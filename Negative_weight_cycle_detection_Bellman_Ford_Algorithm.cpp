//Bellman-Ford Algorithm: To check presence of -ve cycle
//This algorithm calculates shortest path in a graph having -ve weights.
//This can also be used to detect -ve weight cycle.

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

//Here, we are storing every edge and its weight.
vector<int>edgelist[SIZE]; // {u,v,w} , list containg starting vertex, end vertex and weight
int cost[SIZE];//Cost to reach a vertex from source
int parent[SIZE];//To print path to reach a vertex 
bool flag = false;//Most of the graphs require less than N-1 phases, (Optimisation)

bool bellman_ford_negative_cycle(int s,int N){
    cost[s]=0;// Cost to reach source vertex is zero

    //OUTER LOOP MUST BE RUN N-1 TIMES

    for(int i=0; i< N-1; i++){ // Outer loop will run (N-1) times
        int j=0;

        while(edgelist[j].size()==3){  
            
            //Relaxation, if( cost[u] + w(u,v) < cost[v] ) then cost[v] = cost[u] + w(u,v).

            if( cost[ edgelist[j][0] ] + edgelist[j][2] < cost[ edgelist[j][1] ] ){
                cost[ edgelist[j][1] ] = cost[ edgelist[j][0] ]+ edgelist[j][2];
                parent[ edgelist[j][1] ] = edgelist[j][0];
            }
            j++;
        }
    }


        int j=0;
        while(edgelist[j].size()==3){
            //If relaxation happens even after running N-1 phases then graph contains -ve cycle  
            if( cost[ edgelist[j][0] ] + edgelist[j][2] < cost[ edgelist[j][1] ] ){
                cost[ edgelist[j][1] ] = cost[ edgelist[j][0] ]+ edgelist[j][2];
                flag=true;
            }
            j++;
        }

        if(flag==true)
            return true;
        else
            return false;


}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,M;
    cin>>N>>M;
    
    for(int i=0;i<M;i++){
        int x,y,w;
        cin>>x>>y>>w;
        
        //edgelist[i]={u,v,w}
        
        edgelist[i].push_back(x);
        edgelist[i].push_back(y);
        edgelist[i].push_back(w);
     }

     //Initial values
    for(int i=1;i<=N;i++){
        cost[i]=INF;
        parent[i]=-1;
    }
    
    int s;
    cin>>s;
    
    if(bellman_ford_negative_cycle(s,N))//Passing number of nodes to run outer loop
        cout<<"Graph contains -ve weight cycle\n";
    else
        cout<<"Graph doesn't contain -ve weight cycle\n";
   
   return 0;
}

 
