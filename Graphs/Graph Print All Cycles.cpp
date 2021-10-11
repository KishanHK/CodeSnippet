#include <bits/stdc++.h>
using namespace std;

const int N = 10000;

vector<int> graph[N];
vector<int> cycles[N];

set<vector<int> >  cc;

void dfs_cycle(int u,int p,int color[],int mark[],int par[],int &cycleNumber){

        if(color[u] == 2) { //already completely visited
                return;
        }

        if(color[u] == 1) {                   //seen vertex but not completely visited and we come back again->cycle detected
                cycleNumber++;
                vector<int> temp;
                int cur = p;
                temp.push_back(p);
                //mark[cur] = cycleNumber;
                while(cur != u) {               //now backtrack again and update with the cycleNumber
                        cur = par[cur];
                        temp.push_back(cur);
                        //mark[cur] = cycleNumber;
                }
                cc.insert(temp);
                return;
        }
        par[u] = p;
        color[u] = 1;                            //visited vertex partially
        for(auto v:graph[u]) {
                if(v == par[u]) {
                        continue;
                }
                dfs_cycle(v,u,color,mark,par,cycleNumber);
        }

        color[u] = 2;                              //visited completely
}


void addEdge(int u,int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
}

int main(){

        addEdge(1, 2); addEdge(1, 3);
        addEdge(2, 3); addEdge(2, 4);
        addEdge(3, 4); addEdge(4, 5); addEdge(3,5);


        int color[N];
        int par[N];
        int mark[N];

        int cycleNumber = 0;

        dfs_cycle(1,-1,color,mark,par,cycleNumber);

        for(auto vec: cc) {
                for(auto i: vec) {
                        cout<<i<<" ";
                }
                cout<<endl;
        }

        return 0;
}
