#include<bits/stdc++.h>
using namespace std;
int dp[5001][5001];
int edit_dist(string s1, string s2, int n, int m){
    for(int i=0;i<=n;++i){
        for(int j=0;j<=m;++j){
            if(i==0) dp[i][j]=j;
            else if(j==0) dp[i][j]=i;
            else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
        }
    }
    return dp[n][m];
}
int main(){
    string s1,s2; cin>>s1>>s2;
    cout<<edit_dist(s1,s2,s1.size(),s2.size())<<endl;
}