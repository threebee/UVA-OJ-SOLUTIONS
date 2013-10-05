#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
using namespace std;

#define INF 1000000000

typedef pair <int,int> ii;
typedef vector <int>  vi;
typedef vector <ii> vii;
typedef greater <ii> gii;

vector <vii> AdjList;

int main(){
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        int n,m,src,des;
        scanf("%d %d %d %d",&n,&m,&src,&des);

        AdjList.clear();
        AdjList.assign(n,vii());

        for(int i=0;i<m;i++){
            int a,b,dist;
            scanf("%d %d %d",&a,&b,&dist);
            AdjList[a].push_back(ii(dist,b));
            AdjList[b].push_back(ii(dist,a));
        }

        priority_queue <ii,vii,gii> pq;
        vi cost(n,INF);
        cost[src]=0;
        pq.push(ii(0,src));

        while(!pq.empty()){
            ii node=pq.top();  pq.pop();
            int s=node.second;
            int d=node.first;
            if(d==cost[s])
                for(int j=0; j<AdjList[s].size();j++){
                    ii v=AdjList[s][j];

                    if( cost[v.second] > cost[s] + v.first){
                        cost[v.second]=cost[s]+v.first;
                        pq.push(ii(cost[v.second],v.second));
                    }
                }
        }
        if(cost[des]!=INF)
            printf("Case #%d: %d\n",++cas,cost[des]);
        else
            printf("Case #%d: unreachable\n",++cas);
    }
    return 0;
}
