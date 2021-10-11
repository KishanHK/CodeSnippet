#include <bits/stdc++.h>
using namespace std;

struct Edge {
        int src,dest,weight;
};

struct Graph {
        int V,E;
        struct Edge* edge;
};

struct Graph* BuildGraph(int V,int E){
        struct Graph* graph = new Graph;
        graph->V = V;
        graph->E = E;
        graph->edge = new Edge[graph->E];
        return graph;
};

bool isNegCycleBellmanFord(struct Graph* graph,int src){
        int V = graph->V;
        int E = graph->E;
        int dist[V];

        //step 1: intiallize distance form source to all other vertices as INFINITE
        for(int i = 0; i < V; i++) {
                dist[i] = INT_MAX;
        }
        dist[src] = 0;

        //step 2: relax all edges V - 1 times, a simple shortest path from any vertices can have at most V - 1  edges
        for(int i = 1; i <= V-1; i++) {
                for(int j = 0; j < E; j++) {
                        int u = graph->edge[j].src;
                        int v = graph->edge[j].dest;
                        int w = graph->edge[j].weight;
                        if(dist[u] != INT_MAX and dist[u] + w  < dist[v])
                                dist[v] = dist[u] + w;
                }
        }

        //step 3: check for negative weight cycles , the above step guarnteed shortes path if there is no cycles
        //     if we get a shorter path, then there is a cycle
        for(int i  = 0; i < E; i++) {
                int u = graph->edge[i].src;
                int v = graph->edge[i].dest;
                int w = graph->edge[i].weight;
                if(dist[u] != INT_MAX  and dist[u] + w < dist[v]) {
                        return true;
                }
        }

        return false;
}

int main(){
        int V = 5;
        int E = 8;

        struct Graph* graph = BuildGraph(V,E);

        if (isNegCycleBellmanFord(graph, 0))
                cout << "Yes";
        else
                cout << "No";

        return 0;
}

/*
 * given in a directed graph, we need to compute whether the graph has a negatve edge cycle or not.
 * A negative edge cycle is one which the overall sum of the cycle becomes negative
 */
