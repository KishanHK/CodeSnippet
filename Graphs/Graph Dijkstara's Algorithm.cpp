#include <bits/stdc++.h>
using namespace std;

int main(){
        int n, m;
        cin>>n>>m;
        const int INF  = 1e9;

        vector<vector<pair<int,int> > > adj(n+1);

        for(int i = 0; i<m; i++) {
                int u, v, w;
                cin>>u>>v>>w;
                adj[u].push_back({v,w});
                adj[v].push_back({u,w});
        }

        vector<int> dis(n+1,INF);

        int source;
        cin>>source;
        dis[source] = 0;

        set< pair<int,int>  > s;   //min_heap
        s.insert({0,source});

        while(!s.empty()) {
                auto x = *s.begin();
                s.erase(x);
                for(auto it : adj[x.second]) {
                        if(dis[it.first] > dis[x.second] + it.second) {
                                s.erase({dis[it.first], it.first});
                                dis[it.first] = dis[x.second] + it.second;
                                s.insert({dis[it.first], it.first});
                        }
                }

        }

        for(int i = 1; i<=n; i++) {
                if(dis[i] < INF) {
                        cout<<dis[i]<<" ";
                }
                else cout<< -1<<" ";
        }

        return 0;
}

/*
 * Dijkstra's Algorithm will not work when there is negative weight edges Or negative weight cycles are there
 */
