#include <bits/stdc++.h>
using namespace std;

#define N 1000*100 + 5

vector<int> parent(N);
vector<int> size(N);

void make(int v)
{
        parent[v] = v;
        size[v] = 1;
}

int find_set(int v){
        if(v==parent[v])
                return v;
        return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b){
        a = find_set(a);
        b = find_set(b);
        if(a!=b) {
                if(size[a]<size[b])
                        swap(a,b);
                parent[b]=a;
                size[a] += size[b];
        }
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        for(int i = 0; i < N; i++) make(i);

        vector<vector<int> > edges;

        int n,m;
        cin>>n>>m;

        for(int i = 0; i<m; i++)
        {
                int u,v,w;
                cin>>u>>v>>w;
                edges.push_back({w,u,v});
        }

        int cost = 0;
        sort(edges.begin(),edges.end());
        for(auto i: edges) {
                int w = i[0];
                int u = i[1];
                int v = i[2];
                int x = find_set(u);
                int y = find_set(v);

                if(x==y) {
                        continue;   //it means we will not form the cycle and exclude this edge from MST
                }
                else{
                        union_set(u,v);
                        cost+=w;
                }

        }
        cout<<cost;

        return 0;
}

/*
 * The definition of minimum spanning tree is that in a graph every vertex is connected with its edges with minumum cost.
 */
