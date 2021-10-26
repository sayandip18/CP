int longestSubstring(string S) {
    int n = S.size();
    bool dp[n][n];
    memset(dp,0,sizeof(dp));
    int maxLength=1;
    for(int i=0;i<n;++i) dp[i][i]=true;
    int start=0;
    for(int i=0;i<n-1;++i){
        if(S[i]==S[i+1]){
            dp[i][i+1] = true;
            start=i;
            maxLength=2;
        }
    }
    for(int k=3;k<=n;++k){
        for(int i=0;i<n-k+1;++i){
            int j = i+k-1;
            if(dp[i+i][j-1]&&S[i]==S[j]) {dp[i][j] = true;
            if(k>maxLength){start=i; maxLength=k;}}
        }
    }
    return maxLength;
}