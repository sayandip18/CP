#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<pair<int,int> > events;
    for(int i=0;i<n;++i){
        int start, end; cin>>start>>end;
        events.push_back({start, 1});
        events.push_back({end, -1});
    }
    sort(events.begin(), events.end());
    int now=0, res=0;
    for(int i=0;i<events.size();++i){
        now += events[i].second;
        res = max(res, now);
    }
    cout<<res<<endl;
}