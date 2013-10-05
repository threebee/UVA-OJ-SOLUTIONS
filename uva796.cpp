#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
#define DFS_WHITE 0
typedef vector <int> vi;
typedef pair<int,int> ii;

vector <ii> ans;
vector <vi> AdjList;
vi dfs_parent;
vi dfs_low,dfs_num;
vi articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;

int V, total_neighbors, id, weight;

bool cmp(ii a,ii b){
    if(a.first==b.first) return a.second < b.second;
    return a.first < b.first;
}

void Bridge(int u) {
  dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
  for (int j = 0; j < (int)AdjList[u].size(); j++) {
    if (dfs_num[AdjList[u][j]] == DFS_WHITE) {
      dfs_parent[AdjList[u][j]] = u;

      Bridge(AdjList[u][j]);

      if (dfs_low[AdjList[u][j]] > dfs_num[u])
        ans.push_back(ii(min(u,AdjList[u][j]),max(u,AdjList[u][j])));
      dfs_low[u] = min(dfs_low[u], dfs_low[AdjList[u][j]]);
    }
    else if (AdjList[u][j] != dfs_parent[u])
      dfs_low[u] = min(dfs_low[u], dfs_num[AdjList[u][j]]);
  }
}

int main(){
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&V)==1){
         dfsNumberCounter = 0; dfs_num.assign(V, DFS_WHITE); dfs_low.assign(V, 0);
         dfs_parent.assign(V, -1); articulation_vertex.assign(V, 0);
         AdjList.assign(V,vi());
         ans.clear();
         int tmp1,tmp2,tmp3;
         for(int i=0;i<V;i++){
            scanf("%d (%d)",&tmp1,&tmp2);
            while(tmp2--){
                scanf("%d",&tmp3);
                AdjList[tmp1].push_back(tmp3);
                AdjList[tmp3].push_back(tmp1);
            }
         }

         for (int i = 0; i < V; i++)
            if(dfs_num[i]==DFS_WHITE){
                dfsRoot = i;
                Bridge(i);
            }
        if(ans.size()) sort(ans.begin(),ans.end(),cmp);
        printf("%d critical links\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d - %d\n",ans[i].first,ans[i].second);
        printf("\n");
    }
    return 0;
}

