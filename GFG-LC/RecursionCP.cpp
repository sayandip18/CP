#include<bits/stdc++.h>
using namespace std;
string swapString(string s, int left, int i){
    char t;
    t = s[left];
    s[left]=s[i];
    s[i]=t;
    return s;
}
void findPermutation(string s, int left, int right){
    if(left==right) cout<<s<<endl;
    for(int i=left; i<=right; ++i){
        s=swapString(s,left, i);
        findPermutation(s,left+1, right);
        s=swapString(s, left, i);
    }
}

void solve(){
    string s; cin>>s;
    int n=s.size();
    findPermutation(s,0,n-1);
}
int main(){
    int t; cin>>t;
    while(t--){
        solve();
    }
}
