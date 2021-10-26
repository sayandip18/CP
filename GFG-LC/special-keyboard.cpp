#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    long long int optimalKeys(int n){
        // code here
        if(n<=6) return n;
        int dp[n+1];
        for(int i=0;i<=n;++i) dp[i]=i;
        for(int i=7;i<=n;++i){
            for(int j=i-3;j>=1;--j){
                int curr = dp[j]*(i-j-1);
                dp[i] = max(dp[i], curr);
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.optimalKeys(N)<<"\n";
    }
    return 0;
}