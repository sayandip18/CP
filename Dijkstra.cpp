#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 
    // prints shortest path from s
    void shortestPath(int s);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list< pair<int, int> >[V];
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
 

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int,int>> s;
    vector<int> dis(V,INT_MAX);
    s.insert(make_pair(0,S));
    dis[S]=0;
    while(!s.empty()){
        pair<int, int> tmp = *(s.begin());
        s.erase(s.begin());
        int u = tmp.second;
        for(auto x: adj[u]){
            int v = (*x).first;
            int wt = (*x).second;
            if(dis[v]>dis[u]+wt){
                if(dis[v]!=INT_MAX) s.erase(s.find(make_pair(dis[v],v)));
                dis[v]=dis[u]+wt;
                s.insert(make_pair(dis[v],v));
            }
        }
    }
    return dis;
}



int main()
{
    // create the graph given in above fugure
    int V = 9;
    Graph g(V);
 
    //    making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
 
    g.shortestPath(0);
 
    return 0;
}