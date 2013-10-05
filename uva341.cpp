#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
using namespace std;
#define INF 1000000000


typedef pair <int,int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef greater <ii> gii;

vi p;
int src,des;
vector <vii> AdjList;

void print_path(int s){
    if(s == src) {
        printf("%d",s+1);
        return;
    }
    print_path(p[s]);
    printf(" %d",s+1);
}


int main(){
    int N,cas=0;
    while(scanf("%d",&N),N){
        int neighbours;
        AdjList.assign(N,vii());
        for(int i=0;i<N;i++){
            scanf("%d",&neighbours);
            int d,v;
            for(int j=0;j<neighbours;j++){
                scanf("%d %d",&v,&d);
                v--;
                AdjList[i].push_back(ii(v,d));
            }
        }

        scanf("%d %d",&src,&des);
        src--; des--;

        priority_queue < ii , vii , gii > pq;
        pq.push(ii(0,src));
        vi dist(N,INF);
        p.assign(N,0);
        dist[src]=0;

        while(!pq.empty()){
            ii node=pq.top(); pq.pop();
            int d=node.first;
            int u=node.second;

            if(d == dist[u])
                for(int i=0;i<(int)AdjList[u].size();i++){
                    ii tmp=AdjList[u][i];
                    if(dist[tmp.first] > dist[u] + tmp.second){
                        dist[tmp.first]=dist[u]+tmp.second;
                        p[tmp.first]=u;
                        pq.push(ii(dist[tmp.first],tmp.first));
                    }
                }
        }
        printf("Case %d: ",++cas);
        printf("Path = "); print_path(des);
        printf("; %d second delay\n",dist[des]);
    }
    return 0;
}
