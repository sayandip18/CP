#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(int i = a; i < b; i++)
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define inf (1LL<<60)
#define all(x) (x).begin(), (x).end()
#define prDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

vector<int> tree[200001];
int downPath[200001];
int diameter[200001];

void find_dp(int src, int par){
    int best = 0;
    bool leaf = 1;
    for(int child: tree[src]){
        if(child!=par){
            leaf = 0;
            find_dp(child, src);
            best = max(best, downPath[child]);
        }
    }
    if(leaf) downPath[src]=0;
    else downPath[src] = 1+best;
}

void solve(int src, int par){
    int ans=0;
    vector<int> childrenDownPaths;
    for(int child : tree[src])
    {
        if(child != par)
        {
            solve(child, src);
            childrenDownPaths.push_back(downPath[child]);
            ans = max(ans, diameter[child]);
        }
    }
    int numOfchildren = childrenDownPaths.size();
    sort(all(childrenDownPaths));
 
    if(numOfchildren == 0)diameter[src] = 0;
    else if(numOfchildren == 1)diameter[src] = 1 + childrenDownPaths[0];
    else diameter[src] = 2+childrenDownPaths[numOfchildren - 1]+childrenDownPaths[numOfchildren - 2];
 
    diameter[src] = max(diameter[src], ans);
}

int main(){
    fast_io;
    int n; cin>>n;
    fr(0,n-1){
        int u,v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    find_dp(1,0);
    solve(1,0);
    cout<<diameter[1];
}