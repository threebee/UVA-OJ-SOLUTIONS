#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
#define DFS_BLACK 1
#define DFS_WHITE 0

vector <int> topo,visited;
int n,m;
int graph[110][110];

void dfs(int u){
    visited[u]=DFS_BLACK;
    for(int j=1;j<=n;j++){
        if(graph[u][j]){
            if(visited[j]==DFS_WHITE)
                dfs(j);
        }
    }
    topo.push_back(u);
}

int main(){
    while(scanf("%d %d",&n,&m),(n||m)){
        memset(graph,0,sizeof graph);
        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            graph[a][b]=1;
        }
        topo.clear();
        visited.assign(n+1,DFS_WHITE);
        for(int i=1;i<=n;i++){
            if(!visited[i]) dfs(i);
        }
        reverse(topo.begin(),topo.end());
        for(int i=0;i<topo.size()-1;i++) printf("%d ",topo[i]);
        printf("%d\n",topo[topo.size()-1]);
    }
    return 0;
}
