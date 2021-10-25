int knapsack_recursion(int wt[], int val[], int n, int W){
    if(n==0||W==0) return 0;

    if(wt[n-1]<=W) return max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1]), knapsack(wt, val, n-1, W));
    else return knapsack(wt,val,n-1, W);
}

int dp[n+1][W+1];
memset(dp, -1, sizeof(dp));
int knapsack_dp(int wt[], int val[], int n, int W){
    if(n==0||W==0) return 0;
    if(dp[n][W]!=-1) return dp[n][W];
    if(wt[n-1]<=W) return dp[n][W] = max(val[n-1]+knapsack(wt,val,n-1,W-wt[n-1]), knapsack(wt, val, n-1, W));
    else return dp[n][W] = knapsack(wt,val,n-1, W);
}

int knapSack_bottomup(int W, int wt[], int val[], int n)
{
    int i, w;
      vector<vector<int>> K(n + 1, vector<int>(W + 1));
    for(i = 0; i <= n; i++)
    {
        for(w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] +
                                K[i - 1][w - wt[i - 1]],
                                K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}