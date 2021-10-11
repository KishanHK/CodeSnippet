#include <bits/stdc++.h>
using namespace std;
#define fo(i,n) for(int i =0; i<n; i++)

bool iscycle(int src,vector<vector<int> > &adj,vector<bool> &vis,vector<int> &stack)
{
        stack[src] = true;
        if(!vis[src]) {
                vis[src] = true;
                for(auto i:adj[src]) {
                        if(!vis[i] and iscycle(i,adj,vis,stack)) { //work like dfs
                                return true;
                        }
                        if(stack[i])
                                return true;
                }
        }
        stack[src] = false;
        return false;
}

int main()
{
        ios_base::sync_with_stdio(0);
        cin.tie(0);

        int n,m;
        cin>>n>>m;

        const int N = 100;
        vector<vector<int> > adj(N);

        fo(i,m)
        {
                int x,y;
                cin>>x>>y; //x-->y
                adj[x].push_back(y);

        }

        bool cycle = false;

        vector<int> stack(n,0);
        vector<bool> vis(n,0);

        for(int i =0; i<n; i++) //first node is zero
        {
                if(!vis[i] and iscycle(i,adj,vis,stack))
                        cycle  = true;
        }

        if(cycle) cout<<'1';
        else cout<<"NOt presetn";

        return 0;
}


/*
 * Another approach can be
 * call for topolocgial sort, if the length of the returnded list != number of nodes than there is a cycle
 */
