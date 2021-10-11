#include "bits/stdc++.h"
using namespace std;

class Graph {
private:
int V;                                    /*number of vectices*/
vector<vector<int> > adj;
void DFS(int src,bool vis[]);

public:
Graph(int V){
        this->V = V;
        adj = vector< vector<int> >(V);
}
~Graph(){
        adj.clear();
}

void addEdge(int u,int v);
bool isStronglyConnected();
Graph getTranspose();                    /*return reverse(Transpose)*/
};

void Graph::DFS(int src,bool vis[]){
        vis[src] = true;
        cout<<src<<" ";
        for(auto itr : adj[src]) {
                if(!vis[itr]) {
                        DFS(itr,vis);
                }
        }
}

Graph Graph::getTranspose(){
        Graph g(V);
        for(int i = 0; i < V; i++) {
                for(auto itr : adj[i]) {
                        g.adj[itr].push_back(i);
                }
        }
        return g;
}

void Graph::addEdge(int u, int v){
        adj[u].push_back(v);
}

bool Graph::isStronglyConnected(){
        bool vis[V];
        memset(vis,false,sizeof(vis));

        DFS(0, vis);

        for(int i = 0; i < V; i++) {
                if(vis[i] == false) {
                        return false;
                }
        }

        Graph gr = getTranspose();

        memset(vis,false,sizeof(vis));

        gr.DFS(0,vis);

        for(int i = 0; i < V; i++) {
                if(vis[i] == false) {
                        return false;
                }
        }

        return true;
}

int main(){

        Graph g1(5);

        g1.addEdge(0, 1);
        g1.addEdge(1, 2);
        g1.addEdge(2, 3);
        g1.addEdge(3, 0);
        g1.addEdge(2, 4);
        g1.addEdge(4, 2);
        g1.isStronglyConnected()? cout << "Yes\n" : cout << "No\n";

        Graph g2(4);
        g2.addEdge(0, 1);
        g2.addEdge(1, 2);
        g2.addEdge(2, 3);
        g2.isStronglyConnected()? cout << "Yes\n" : cout << "No\n";

        return 0;
}
