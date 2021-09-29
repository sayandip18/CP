#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v(n);
    multiset<int> res;
    for(auto &a: v) cin>>a;
    for(int i=0;i<n;++i){
        if(res.size()==0) res.insert(v[i]);
        else {
            auto base = res.upper_bound(v[i]);
            if(base == res.end()) res.insert(v[i]);
            else {
                res.insert(v[i]);
                res.erase(base);
            }
        }
    }
    cout<<res.size()<<endl;
}