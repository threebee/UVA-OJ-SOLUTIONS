#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <string>
using namespace std;
#define INF 1000000000
#define DFS_WHITE -1

typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;

vector <vii> AdjList;
map <string,int> mp;
map <int,string> rmp;

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
      vector <string> ans;
      while (1) {
        int v = S.back(); S.pop_back(); visited[v]=0;
        ans.push_back(rmp[v]);
        if(v==u) break;
      }
      for (int i=0;i<ans.size();++i)  {
        if(i>0) cout<<", ";
        cout<<ans[i];
     }
     printf("\n");
  }
}

int main(){
    bool blank=false;
    int V,E,cas=0;
    while(scanf("%d %d",&V,&E),(V||E)){
        AdjList.assign(V,vii());
        mp.clear();
        rmp.clear();
        int id=0;
        string str1,str2;
        for(int i=0; i<E; i++){
            cin>>str1>>str2;
            if(!mp.count(str1)){
               mp[str1]=id;
               rmp[id]=str1;
               id++;
            }
            if(!mp.count(str2)){
                mp[str2]=id;
                rmp[id]=str2;
                id++;
            }
            AdjList[mp[str1]].push_back(ii(mp[str2],1));
        }
        if(blank) printf("\n"); blank=true;
        dfs_num.assign(V, DFS_WHITE);
        dfs_low.assign(V, 0);
        visited.assign(V, 0);
        dfsNumberCounter = numSCC = 0;
        printf("Calling circles for data set %d:\n",++cas);
        for(int i=0;i<V;i++){
          if(dfs_num[i]==DFS_WHITE){
            tarjanSCC(i);
          }
        }
    }
    return 0;
}
