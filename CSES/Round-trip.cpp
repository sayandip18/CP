#include<bits/stdc++.h>
using namespace std;

int n, m, sv, ev;

vector<vector<int>> g;
vector<bool> vis;
vector<int> par;

// Modified dfs to detect cycle
bool detect_cycle(int u, int p){
    vis[u]=true;
    par[u] = p;
    for(auto v:g[u]){
        if(v==p) continue;
        if(vis[v]){
            sv=v;
            ev=u;
            return true;
        }
        if(!vis[v]){
            if(detect_cycle(v,u)) return true;
        }
    }
    return false;
}

bool visit_all(){
    for(int i=1;i<=n;++i){
        if(!vis[i]) {
            if(detect_cycle(i, -1)) return true;
        }
    }
    return false;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    par.resize(n+1);
    for(int i=0;i<m;++i){
        int u,v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(!visit_all()) cout<<"IMPOSSIBLE";
    else {
        vector<int> res;
        res.push_back(ev);
        int tv = ev;
        while(tv!=sv){
            tv=par[tv];
            res.push_back(tv);
        }
        res.push_back(ev);
        cout<<res.size()<<endl;
        for(auto x: res) cout<<x<<' ';
    }
    
}