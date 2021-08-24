#include<bits/stdc++.h>
using namespace std;
int knapsack(int W, int v[], int wt[], int n){
    vector<vector<int>> dp(n + 1, vector<int>(W + 1));
    for(int i=0;i<=n;++i){
        for(int w=0;w<=W;++w){
            if (i == 0 || w == 0) dp[i][w]=0;
            else if(wt[i-1]>w) dp[i][w]=dp[i-1][w];
            else dp[i][w]=max(dp[i-1][w], dp[i-1][w-wt[i-1]]+v[i-1]);
        }
    }
    return dp[n][W];
}
int main(){
    int h[1001], s[1001], n, x;
    cin>>n>>x;
    for(int i=0;i<n;++i) cin>>h[i];
    for(int i=0;i<n;++i) cin>>s[i];
    cout<<knapsack(x,s,h,n)<<endl;
}