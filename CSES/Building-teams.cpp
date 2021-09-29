#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<int> > g;
vector<int> col;

bool bipartite(){
    queue<pair<int, int> > q;
    for(int i=1;i<=n;++i){
        if(col[i]==-1){
            q.push({i, 0});
            col[i]=0;
            while(!q.empty()){
                pair<int,int> p = q.front();
                q.pop();
                int v = p.first;
                int c = p.second;
                for(auto j: g[v]){
                    if(col[j]==c) return 0;
                    if(col[j]==-1) {
                        col[j]=c?0:1;
                        q.push({j,col[j]});
                    }
                }
            }
        }
    }
    return 1;
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    col.resize(n+1);
    for(int i=0;i<=n;++i) col[i]=-1;
    for(int i=1;i<=m;++i){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bool res = bipartite();
    if(!res) {cout<<"IMPOSSIBLE"<<endl; return 0;}
    else {
        for(int i=1;i<=n;++i) cout<<1+col[i]<<' ';
    }
}