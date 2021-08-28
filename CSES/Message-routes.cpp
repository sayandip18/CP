#include<bits/stdc++.h>
using namespace std;

int n,m;

vector<vector<int> > g;
bool vis[100001];
int par[100001];

void bfs(){
    vis[1] = true;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: g[u]){
            if(!vis[v]){
                vis[v]=true;
                par[v]=u;
                q.push(v);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    g.resize(n+1);
    for(int i=0;i<m;++i){
        int u, v; cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 0; i<=n; ++i) par[i] = -1;
    bfs();
    if(par[n]==-1){cout<<"IMPOSSIBLE"<<endl; return 0;}
    stack<int> s;
    while(n!=-1){
        s.push(n); n=par[n];
    }
    cout<<s.size()<<endl;
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }
	
}