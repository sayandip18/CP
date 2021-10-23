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


int main(){
    fast_io;
    int n; cin>>n;
    fr(0,n-1){
        int u,v; cin>>u>>v;
        tree[u].pb(v);
        tree[v].pb(u);
    }
}