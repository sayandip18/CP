#include<bits/stdc++.h>
using namespace std;
void add_edge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void DFSUtil(vector<int> adj[], int u, vector<bool> visited){
    visited[u] = true;
    for (int i=0; i<adj[u].size(); i++) {
        if(!visited[adj[u][i]]) DFSUtil(adj, adj[u][i], visited);
    }
}
void DFS(vector<int> adj[], int v){
    vector<bool> visited(v, false);
    for(int i=0;i<v;++i){
        if(!visited[i]) DFSUtil(adj, i, visited);
    }
}
vector<bool> visited_bfs;
void BFS(vector<int> adj[], int u){
    queue<int> q; q.push(u);
    visited_bfs[u]=true;
    while(!q.empty()){
        int f = q.front(); q.pop();
        for(auto x=adj[u].begin(); x!=adj[u].end(); x++){
            if(!visited_bfs[*x]) {q.push(*x); visited_bfs[*x]=true;}
        }
    }
}
int main(){
    int v; cin>>v; //number of vertices of the graph
    vector<int> adj[v];
    
}