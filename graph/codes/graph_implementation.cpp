#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define endl '\n'

const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;


class graph{
public:
    map<int,vector<int>> adj_list;
    void add_edge(int u,int v,bool is_directed=false){
        adj_list[u].push_back(v);
        if(!is_directed) adj_list[v].push_back(u);
    }
    void print_graph(){
        for(auto i:adj_list){
            cout<<i.first<<" -> ";
            for(auto j:i.second) cout<<j<<" ";
            cout<<endl;
        }
    }
};
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
   int n ;
   cout<<"Enter the number of nodes: ";
   cin>>n;
   int m;
   cout<<"Enter the number of edges: ";
   cin>>m;
   graph g;
   for(int i=0;i<m;i++){
    int u,v;
    cout<<"Enter the edge: ";
    cin>>u>>v;
    g.add_edge(u,v,0);
   }
   g.print_graph();
}