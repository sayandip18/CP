// recursion
int lcs(string x, string y, int n, int m){
    if(n==0||m==0) return 0;
    if(x[n-1]==y[m-1]) return 1+lcs(x,y,n-1,m-1);
    else return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
}

// top down
int dp[n+1][m+1];
int lcs(string x, string y, int n, int m){
    if(n==0||m==0) return 0;
    if(dp[n-1][m-1]!=-1) return dp[n-1][m-1];
    if(x[n-1]==y[m-1]) return dp[n-1][m-1] = 1+lcs(x,y,n-1,m-1);
    else return dp[n-1][m-1] = max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
}

// bottom up
int lcs(string x, string y, int n, int m){
    int dp[n+1][m+1];
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
        if (i == 0 || j == 0)
            dp[i][j] = 0;
    
        else if (x[i-1] == y[j-1])
            dp[i][j] = dp[i-1][j-1] + 1;
    
        else
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
