#include<bits/stdc++.h>
using namespace std;
long long MOD = 1e9+7;
long long dp[1000005];
int main(){
    cin.sync_with_stdio(false);
    int n;
    cin >> n;
    dp[1]=1; dp[2]=2; dp[3]=4; dp[4]=8; dp[5]=16; dp[6]=32;
    for(int i=1;i<=n;++i){
        if(i<=6) continue;
        else dp[i]=((dp[i-1])%MOD+(dp[i-2])%MOD+(dp[i-3])%MOD+(dp[i-4])%MOD+(dp[i-5])%MOD+(dp[i-6])%MOD)%MOD;
    }
    cout<<dp[n];
}
