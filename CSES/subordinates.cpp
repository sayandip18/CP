#include<bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

vector<int> tree[200001];

void solve(int src, int par, vector<int>& ans)
{
    int subords = 0;
    for(int child : tree[src])
    {
        if(child != par)
        {
            solve(child, src, ans);
            subords += (1 + ans[child]);
        }
    }
    ans[src] = subords;
}

int main(){
    fast_io;
    int n; cin>>n;
    vector<int> ans(n+1);
    for(int i=2;i<n+1;++i){
        int x; cin>>x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    solve(1,0,ans);
    for(int i=1;i<n+1;++i) cout<<ans[i]<<' ';
}