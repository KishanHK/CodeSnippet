#include <bits/stdc++.h>
using namespace std;

#define N  1000*100

vector<vector<int> > adj(N);
vector<bool> vis(N,false);

int getCom(int idx)
{
        if(vis[idx]) return 0;
        vis[idx] =true;
        int ans = 1;
        for(auto i:adj[idx]) {
                if(!vis[i]) {
                        ans+=getCom(i);
                        vis[i]=true;
                }
        }
        return ans;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, m; cin>>n>>m;

        vector<int>  components;

        for(int i = 0; i < m; i++)
        {
                int u,v;
                cin>>u>>v;
                adj[u].pb(v);
                adj[v].pb(u);
        }

        for(int i = 0; i < n; i++)
        {
                if(!vis[i])
                {
                        components.pb(getCom(i));
                }
        }

        for(auto i:components)
        {
                cout<<i<<" ";
        }
        return 0;
}
