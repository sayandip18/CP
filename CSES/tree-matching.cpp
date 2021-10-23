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
int dp[200001][2];

void solve(int src, int par){
    vector<int> prefix, suffix;
    dp[src][0]=0; dp[src][1]=0;
    bool leaf = true;

    for(int child: tree[src]){
        if(child!=par){
            leaf = false;
            solve(child, src);
        }
    }

    if(leaf) return;

    for(int child: tree[src]){
        if(child!=par){
            prefix.push_back(max(dp[child][0], dp[child][1]));
            suffix.push_back(max(dp[child][0], dp[child][1]));
        }
    }

    fr(1, (int)prefix.size()) prefix[i]+=prefix[i-1];
    for(int i=(int)suffix.size()-2; i>=0; --i) suffix[i]+=suffix[i+1];

    dp[src][0] = suffix[0];

    int c_no = 0;
    for(int child: tree[src]){
        if(child == par) continue;
        int leftchild = (c_no==0)?0:prefix[c_no-1];
        int rightchild = (c_no==(int)suffix.size()-1)?0:suffix[c_no+1];
        dp[src][1] = max(dp[src][1], 1+leftchild+rightchild+dp[child][0]);
        c_no++;
    }
}

int main(){
    fast_io;
    ll n; cin>>n;
    fr(2, n+1){
        int u,v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
    solve(1,0);
    cout<<max(dp[1][0], dp[1][1]);
}