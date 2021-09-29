#include<bits/stdc++.h>
using namespace std;
int recurse(string s, int start, int end){
    if(start==end) return 1;
    if(s[start]==s[end] && start+1==end) return 2;
    if(s[start]==s[end]) return recurse(s,start+1, end-1)+2;
    return max(recurse(s,start+1, end), recurse(s, start, end-1));

}
int dp(string s){
    int n = s.size();
    int arr[n][n];
    for(int i=0;i<n;++i) arr[i][i] = 1;
    for(int cl=2;cl<=n;++cl){
        for(int i=0;i<n-cl+1;++i){
            int j = i+cl-1;
            if(s[i]==s[j] && cl==2) arr[i][j]=2;
            else if(s[i]==s[j]) arr[i][j] = arr[i+1][j-1] + 2;
            else arr[i][j] = max(arr[i+1][j], arr[i][j-1]);
        }
    }
    return arr[0][n-1];
}
int main(){
    string s;
    cin>>s;
    int n = s.size()-1;
    cout<<recurse(s, 0, n)<<endl<<dp(s);
    
}