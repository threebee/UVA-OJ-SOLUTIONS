#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

typedef pair <int,int> ii;
typedef vector <int> vi;

vector <vi> AdjList;

int main(){
    int neighbours,n,m,counter,source,destination,tmp,query;
    int cas=0;
    while(scanf("%d",&neighbours)==1){
        AdjList.assign(20,vi());
        counter=0;
        for(int i=0;i<neighbours;i++){
            scanf("%d",&tmp);  tmp--;
            AdjList[counter].push_back(tmp);
            AdjList[tmp].push_back(counter);
        }

        for(counter=1;counter<19;counter++){
            scanf("%d",&neighbours);
            for(int j=0;j<neighbours;j++){
                scanf("%d",&tmp); tmp--;
                AdjList[counter].push_back(tmp);
                AdjList[tmp].push_back(counter);
            }
        }

        scanf("%d",&query);
        printf("Test Set #%d\n",++cas);

        while(query--){
            scanf("%d %d",&source,&destination);
            source--; destination--;
            map <int,int> dist; dist[source]=0;
            queue <int> q;  q.push(source);

            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int i=0;i<(int)AdjList[u].size();i++){
                    int tmp=AdjList[u][i];
                    if(!dist.count(tmp)){
                        dist[tmp]=dist[u]+1;
                        q.push(tmp);
                    }
                }
            }
            printf("%2d to %2d: %d\n",source+1,destination+1,dist[destination]);
        }
        printf("\n");
    }
    return 0;
}
