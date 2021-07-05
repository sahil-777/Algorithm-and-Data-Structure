//DSU- Disjoint Set Union
//Disjoint Set Union Operations:
// make_set(x):make new set having only element x
// find_set(x): find the set from which x belongs
// union(x,y):merge two different sets containing x & y 

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
#define INF  1e9+1
#define ll   long long  
#define mod  1e9+7

//ll nodes[SIZE];
ll parent[SIZE];//To store Parent of a node
ll Rank[SIZE];//For Union by Rank

void make_set(ll node){// Creates a set having single node
    parent[node]=node;
    Rank[node]=0;
}

ll find_set(ll node){//Returns leader of the set containing given node 
    if(parent[node]==node)
        return node;
    return parent[node]=find_set(parent[node]);//Path Compression      
}

void Union(ll a, ll b){//Union of different sets containing nodes a & b
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(Rank[a]<Rank[b])// b>=a, require condition
            swap(a,b);
        parent[b]=a;
        if(Rank[a]==Rank[b]){
            Rank[a]++;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll N,M;
    cin>>N>>M;

    for(ll i=1;i<=N;i++){
        make_set(i);
    }

    while(M--){
        ll x,y;
        cin>>x>>y;
        Union(x,y);
    }
    ll Q;
    cin>>Q;
    while(Q--){
        ll x;
        cin>>x;
        cout<<"Set leader => "<<find_set(x)<<"\n";
    }    
    return 0; 
}
 