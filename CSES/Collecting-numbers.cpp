#include<bits/stdc++.h>
using namespace std;
int a[200004];
int b[200004]={0};
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
        b[a[i]]=i;
    }
    int res=1;
    for(int i=1;i<=n;++i) {
        if(b[i]<b[i-1]) res++;
    }
    cout<<res;
}