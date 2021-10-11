#include <bits/stdc++.h>
using namespace std;

#define N 100*1000

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n, m;
        cin >> n >> m;

        vector<vector<int> > adj(n + 1);
        vector<int> indeg(n + 1, 0);

        for (int i = 0; i < m; i++)
        {
                int x, y;
                cin >> x >> y;
                adj[x].pb(y);
                indeg[y]++;
        }

        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
                if (indeg[i] == 0)
                        q.push(i);
        }

        while (!q.empty())
        {
                int x  = q.front();
                q.pop();
                cout << x << " ";
                for (auto it : adj[x])
                {
                        indeg[it]--;
                        if (indeg[it] == 0)
                                q.push(it);
                }
        }
}

/*
 * topological ordering is an ordering of the nodes in a directed graph for each directed edge from a to b,
 * node a appears before node b
 */


/*
   time Complexity of the below code is O(v^2 + v + e)

   Topological_sort(Graph G){
        find vertix with indeg = 0;
        push that vertex into linked list;
        delete that vertex;
        Topological_sort(G);
   }
 */
