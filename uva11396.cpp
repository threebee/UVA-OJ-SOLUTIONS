/*
11396 - Claw Decomposition
bipartite check!!!
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
#include <vector>
using namespace std;
typedef vector <int> vi;

int main(){
    int n,m,a,b;
    while(scanf("%d",&n),n){
        vector <vi> graph;
        graph.assign(n+1,vi());
        while(scanf("%d %d",&a,&b),(a||b)){
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        bool bipartite;
        queue <int> q;
        map <int,int> mp;

        for(int i=1;i<=n;i++){
            if(mp.count(i)) continue;
            mp[i]=0;
            bipartite=true;
            q.push(i);
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int j=0;j<graph[u].size();j++){
                    if(!mp.count(graph[u][j])){
                        mp[graph[u][j]]=1-mp[u];
                        q.push(graph[u][j]);
                    }
                    else if(mp[graph[u][j]]==mp[u]){
                       bipartite=false;
                    }
                }
            }
            if(!bipartite) break;
        }
        if(bipartite) printf("YES\n");
        else          printf("NO\n");
    }
    return 0;
}
