/*
  strongly connected component with 0 indegree
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define INF 1000000000
#define DFS_WHITE -1

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;

int dfs_counter,numSCC;
vi visited,dfs_num,dfs_low,S,id;

void tarjanSCC(int u){
    dfs_num[u]=dfs_low[u]=dfs_counter++;
    visited[u]=1;
    S.push_back(u);
    for(int j=0;j<(int)AdjList[u].size();j++){
        ii v=AdjList[u][j];
        if(dfs_num[v.first]==DFS_WHITE)
            tarjanSCC(v.first);
        if(visited[v.first])
            dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);
    }

    if(dfs_low[u]==dfs_num[u]){
       while(1){
         int v=S.back(); S.pop_back(); visited[v]=0;
         id[v]=numSCC;
         if(v==u) break;
       }
       numSCC++;
    }
}

int main(){
    int n,m,t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        visited.assign(n,0);
        dfs_num.assign(n,DFS_WHITE);
        dfs_low.assign(n,0);
        id.assign(n,-1);
        dfs_counter=numSCC=0;

        AdjList.assign(n,vii());
        int a,b;

        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            a--,b--;
            AdjList[a].push_back(ii(b,1));
        }

        S.clear();
        for(int i=0;i<n;i++)
          if(dfs_num[i]==DFS_WHITE)
            tarjanSCC(i);

        vi in(n,0);
        int tot=0;

        for(int i=0;i<n;i++)
        for(int j=0;j<AdjList[i].size();j++){
            ii tmp=AdjList[i][j];
            if(id[i]!=id[tmp.first]){
                in[id[tmp.first]]++;
            }
        }

        for(int i=0;i<numSCC;i++)
           if(!in[i]) tot++;

        printf("Case %d: %d\n",++cas,tot);
    }
    return 0;
}
