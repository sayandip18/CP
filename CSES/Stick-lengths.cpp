#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    int n; cin>>n;
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    int mid;
    if(n%2==1) mid=a[n/2];
    else mid = (a[n / 2] + a[(n - 2) / 2]) / 2;
    long long res=0;
    for(int i=0;i<n;++i) res+=abs(a[i]-mid);
    cout<<res;
}