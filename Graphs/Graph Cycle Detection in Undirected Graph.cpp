#include <bits/stdc++.h>
using namespace std;

bool iscycle(int src, int parent, vector<bool> &vis, vector<vector<int>  > &adj){
        vis[src] = true;
        for(auto it : adj[src]) {
                if(it != parent) {
                        if(vis[it]) return true;
                        if(!vis[it] and iscycle(it,src,vis,adj)) return true;
                }
        }
        return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
        vector<bool> vis(A+1,false);
        bool cycle = false;
        vector<vector<int> > adj(A+1);
        for(int i= 0; i<B.size(); i++) {
                int x = B[i][0];
                int y = B[i][1];
                adj[x].push_back(y);
                adj[y].push_back(x);
        }
        for(int i = 1; i<=A; i++) {
                if(!vis[i] and iscycle(i, -1,vis,adj))
                        cycle = true;
        }
        return cycle;
}

int main(){

        return 0;
}
