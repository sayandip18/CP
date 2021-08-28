#include<bits/stdc++.h>
using namespace std;

int n,m, cc=0;
vector<vector<int> > g;
vector<bool> vis;
vector<int> lead;

void dfs(int u){
    vis[u] = true;
    for(auto v: g[u]){
        if(!vis[v]) dfs(v);
    }
}

void process_cc(){
    for(int i=1;i<=n;++i){
        if(!vis[i]){
            cc++;
            lead.push_back(i);
            dfs(i);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1);
    for(int i=0;i<m;++i){
        int a,b; cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    process_cc();
    cout<<cc-1<<endl;
    if(cc > 1 )
	{
		int u = lead[0]; int v;
		for(auto i = 1; i < cc; i++)
		{
			v = lead[i];
			cout << u << " " << v << endl;
			u = v;
		}
	}
}