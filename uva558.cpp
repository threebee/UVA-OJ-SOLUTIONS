#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
#define INF 1000000000

typedef vector<int> vi;
typedef pair <int,int> ii;
typedef vector < ii > vii;

vector < vii > AdjList;

int main(){
    int t,V,E,distance,a,b;
    scanf("%d",&t);
    while(t--){
       scanf("%d %d",&V,&E);
       AdjList.assign(V,vii());

       for(int i=0; i<E ;i++){
            scanf("%d %d %d",&a,&b,&distance);
            AdjList[a].push_back(ii(b,distance));
       }

       vi dist(V, INF); dist[0] = 0;
       for (int i = 0; i < V - 1; i++)
         for (int u = 0; u < V; u++)
         for (int j = 0; j < (int)AdjList[u].size(); j++){
            ii v = AdjList[u][j];
            dist[v.first] = min(dist[v.first], dist[u] + v.second);
         }

        bool hasNegativeCycle = false;

        for (int u = 0; u < V; u++)
          for (int j = 0; j < (int)AdjList[u].size(); j++) {
            ii v = AdjList[u][j];
            if (dist[v.first] > dist[u] + v.second)
                hasNegativeCycle = true;
          }

        printf("%s\n", hasNegativeCycle ? "possible" : "not possible");
    }
    return 0;
}
