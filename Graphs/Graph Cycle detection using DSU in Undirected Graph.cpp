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
                int u,v;
                cin>>u>>v;
                edges.push_back({u,v});
        }

        bool cycle = false;
        for(auto i: edges) {

                int u = i[0];
                int v = i[1];

                int x = find_set(u);
                int y = find_set(v);

                if(x==y) {
                        cycle = true;
                }
                else union_set(u,v);
        }

        if(cycle) cout<<"YES";
        else cout<<"NO";

        return 0;
}
