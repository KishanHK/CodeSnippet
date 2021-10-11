#include <bits/stdc++.h>
using namespace std;

#define N 1000*100

vector<vector<int> > adj(N);
vector<bool> vis(N, false);
vector<int> col(N, -1);

bool bi;

void  docol(int u, int curr_color)
{
        if (col[u] != -1 && col[u] != curr_color) {
                bi = false;
                return;
        }
        col[u] = curr;
        if(vis[u] == false) {
                vis[u] = true;
                for (auto it : adj[u]) {
                        docol(it, curr_color xor 1);
                }
        }
        return;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, m;
        cin >> n >> m;
        fo(i, m)
        {
                int x, y;
                cin >> x >> y;
                adj[x].pb(y);
                adj[y].pb(x);
        }

        bi = true;

        for (int i = 1; i <= n; i++)
        {
                if (!vis[i]) {
                        docol(i, 1);
                }

        }

        if(bi) cout << "bipartite";
        else cout << "NO";

        return 0;
}
