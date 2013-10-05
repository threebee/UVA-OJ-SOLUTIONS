
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define INF 1000000000
#define DFS_WHITE -1

typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

vector <vii> AdjList;

vi dfs_num, dfs_low, visited, S;
int dfsNumberCounter,numSCC;

void tarjanSCC(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  S.push_back(u);
  visited[u] = 1;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    ii v = AdjList[u][j];
    if (dfs_num[v.first] == DFS_WHITE)
      tarjanSCC(v.first);
    if (visited[v.first])
      dfs_low[u] = min(dfs_low[u], dfs_low[v.first]);
  }

  if (dfs_low[u] == dfs_num[u]) {
         ++numSCC;
    while (1) {
      int v = S.back(); S.pop_back();
      if (u == v) break;
    }
} }
int main(){
    int V,E;
    while(scanf("%d %d",&V,&E),(V||E)){
        AdjList.assign(V,vii());
        for(int i=0; i<E; i++){
            int a,b,p;
            scanf("%d %d %d",&a,&b,&p);
            a--,b--,p--;
            AdjList[a].push_back(ii(b,1));
            if(p) AdjList[b].push_back(ii(a,1));
        }

        dfs_num.assign(V, DFS_WHITE);
        dfs_low.assign(V, 0);
        visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;

        tarjanSCC(0);
        if(numSCC < 2 && dfsNumberCounter==V ) printf("1\n");
        else    printf("0\n");
    }
    return 0;
}
