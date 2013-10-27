#include <iostream>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;

#define INF 1000000000

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vi> AdjList;

int main(){
    int V,neighbors,tmp,t,source;
    scanf("%d",&V);
    AdjList.assign(V,vi());

    for(int i=0;i<V;i++){
        scanf("%d",&neighbors);
        for(int j=0;j<neighbors;j++){
            scanf("%d",&tmp);
            AdjList[i].push_back(tmp);
        }
    }

    scanf("%d",&t);
    while(t--){
        scanf("%d",&source);
        queue <int> q; q.push(source);
        map <int,int> dist; dist[source]=0;
        vi boom(V,0);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int j=0;j<(int)AdjList[u].size();j++){
                int v=AdjList[u][j];
                if(!dist.count(v)){
                    dist[v]=dist[u]+1;
                    q.push(v);
                    boom[dist[v]]++;
                }
            }
        }
        if(!(int)AdjList[source].size()){
            printf("0\n");
            continue;
        }

        int maxI=0,maxV=-INF;
        for(int i=0; i<V; i++){
            if(maxV<boom[i]){
                maxV=boom[i];
                maxI=i;
            }
        }
        printf("%d %d\n",maxV,maxI);
    }
    return 0;
}
