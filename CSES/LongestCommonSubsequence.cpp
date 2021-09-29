#include<bits/stdc++.h>
using namespace std;
int dp(string s1, string s2){
    int n1=s1.size(), n2=s2.size();
    int arr[n1+1][n2+1];
    for(int i=0;i<=n1;++i) arr[i][0] = 0;
    for(int i=1;i<=n2;++i) arr[0][i] = 0;
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n2;++j){
            if(s1[i-1]==s2[j-1]) arr[i][j] = 1+arr[i-1][j-1];
            else arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
        }
    }
    return arr[n1][n2];
}
int main(){
    string s1, s2; cin>>s1>>s2;
    cout<<dp(s1, s2);
}