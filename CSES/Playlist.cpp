#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int> songs(n);
    for(int i=0;i<n;++i) cin>>songs[i];
    set<int> heard;
    int i=0, j=0;
    int res=0;
    while(i<n && j<n){
        while(j<n && !heard.count(songs[j])){
            heard.insert(songs[j]);
            res = max(res, j-i+1);
            j++;
        }
        while(j<n && heard.count(songs[j])){
            heard.erase(songs[i]);
            ++i;
        }
    }
    cout<<res;
}