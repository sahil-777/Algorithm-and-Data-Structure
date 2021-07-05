#include <bits/stdc++.h>
using namespace std;
#define ll long long
string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

#define SIZE (ll)1e5+1

struct edge{
    ll u;
    ll v;
    ll weight;
};

vector<edge>vstr;

bool compare_weights(struct edge &a,struct edge &b){
    return a.weight < b.weight;
}

ll Rank[SIZE];
ll parent[SIZE];
ll sum[SIZE];

void make_set(ll i){
    Rank[i]=1;
    sum[i]=0;
    parent[i]=i;
}

ll find_set(ll i){
    if(parent[i]==i)
        return i;
    return parent[i]=find_set(parent[i]);
}

void Union(ll x, ll y,ll weight){
    x=find_set(x);
    y=find_set(y);

    if(x!=y){
        if(Rank[x]<Rank[y])
            swap(x,y);

        sum[find_set(x)]+=sum[find_set(y)]+weight;
        parent[y]=x;

        if(Rank[x]==Rank[y])
            Rank[x]++;
        
        //cout<<sum[find_set(x)]<<" "<<sum[find_set(y)]<<" ";
        //sum[find_set(x)]+=sum[find_set(y)]+weight;
        //sum[find_set(y)]=sum[find_set(x)];
        //cout<<sum[find_set(x)]<<" "<<sum[find_set(y)]<<"\n";
    }

  //  sum[find_set(x)]=
}

ll kruskals(ll g_nodes, vector<ll> g_from, vector<ll> g_to, vector<ll> g_weight) {
    ll N=g_nodes,M=(ll)g_weight.size();
    ll i,j;

    for(i=0;i<=N;i++){
        make_set(i);
    }

    vstr.clear();

    for(i=0;i<M;i++){
        edge temp;
        temp.u=g_from[i];
        temp.v=g_to[i];
        temp.weight=g_weight[i];
        vstr.push_back(temp);
    }

    sort(vstr.begin(),vstr.end(),compare_weights);

    for(i=0;i<M;i++){
        ll u=vstr[i].u;
        ll v=vstr[i].v;
        ll weight=vstr[i].weight;

        ll s1=find_set(u);
        ll s2=find_set(v);

        if(s1==s2)
            continue;
        Union(u,v,weight);
    }

    return sum[find_set(1)];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    ll g_nodes = stoi(g_nodes_edges[0]);
    ll g_edges = stoi(g_nodes_edges[1]);

    vector<ll> g_from(g_edges);
    vector<ll> g_to(g_edges);
    vector<ll> g_weight(g_edges);

    for (ll i = 0; i < g_edges; i++) {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        ll g_from_temp = stoi(g_from_to_weight[0]);
        ll g_to_temp = stoi(g_from_to_weight[1]);
        ll g_weight_temp = stoi(g_from_to_weight[2]);

        g_from[i] = g_from_temp;
        g_to[i] = g_to_temp;
        g_weight[i] = g_weight_temp;
    }

    ll res = kruskals(g_nodes, g_from, g_to, g_weight);

    fout<<res<<"\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
