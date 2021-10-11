#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){

        int n, m;
        cin>>n>>m;

        vector<vector<int > > adjm(n+1,vector<int> (n+1,INF));

        for(int i =0; i<m; i++) {
                int u,v,w;
                cin>>u>>v>>w;
                adjm[u][v] = w;
        }

        for(int k = 1; k<=n; k++) {
                for(int i =1; i<=n; i++) {
                        for(int j = 1; j<=n; j++) {
                                adjm[i][j] = min(adjm[i][j], adjm[i][k] + adjm[k][j]);
                        }
                }
        }

        for(int i =1; i<=n; i++) {
                for(int j =1; j<=n; j++) {
                        cout<<adjm[i][j]<<"  ";
                }
                cout<<endl;
        }
        return 0;
}

/*
 * It is similar to Bellman ford Algorithm , here we are also relaxing edges n - 1 times
 */
