#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main(){
    while(1){
        int V,E,id,weight,total_neb;
        bool flag=false;
        scanf("%d",&V);
        if(V==0) break;
        scanf("%d",&E);
        vector<vii> AdjList;
        queue<int> q;
        map<int,int> dist;

        AdjList.assign(V,vii());
        for(int i=0;i<E;i++){
         scanf("%d %d",&id,&weight);
         AdjList[id].push_back(ii(weight,1));
        }
        dist[0]=0;
        q.push(0);
        while(!q.empty()){
            int u=q.front(); q.pop();
            for(int j=0;j<(int)AdjList[u].size();j++){
                ii v=AdjList[u][j];
                if(!dist.count(v.first)){
                    dist[v.first]=1-dist[u];
                    q.push(v.first);
                }
                else{
                    if(dist[v.first]==dist[u]){
                        flag=true;
                        break;
                    }
                }
           }
        }
        if(flag) printf("NOT BICOLORABLE.\n");
        else printf("BICOLORABLE.\n");
    }
    return 0;
}
