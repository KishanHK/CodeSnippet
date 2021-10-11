#include <bits/stdc++.h>
using namespace std;

int main(){
        int n, m;
        cin>>n>>m;

        vector<vector < int> > edges;
        vector<int> dis(n+1,INF);

        for(int i = 0; i<m; i++) {
                int u, v, w;
                cin>>u>>v>>w;
                edges.push_back({u,v,w});
        }

        int src;
        cin>>src;
        dis[src] = 0;

        for(int itr = 0; itr < n - 1; itr++) {
                for(auto e:edges) {
                        int u = e[0];
                        int v = e[1];
                        int w = e[2];
                        dis[v] = min(dis[v], w + dis[u]);
                }
        }

        for(int i = 1; i<=n; i++) {
                cout<<dis[i]<<" ";
        }

        return 0;
}

/*
 *->here we are relaxing every edge n - 1 times.
 * It wcan be used to detect negative edge cycles
 */
