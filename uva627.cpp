/*
  do test before submitting!!!
*/

#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef pair<int,int> ii;
typedef vector <int> vi;

vector <vi> AdjList;
vi p;
char input[1000],*pch;
int n,m,query,src,desc;

void printPath(int u) {
    if (u == src) { printf("%d",src+1); return; }
    printPath(p[u]);
    printf(" %d",u+1);
}

int main(){
    //freopen("output.txt","w",stdout);
    while(scanf("%d",&n)==1){
        AdjList.assign(n,vi());
        getchar();
        for(int i=0;i<n;i++){
            gets(input);
            pch=strtok(input,"-,");
            int id=atoi(pch); id--;
            for(pch=strtok(NULL,"-,");pch;pch=strtok(NULL,"-,")){
                int tmp=atoi(pch); tmp--;
                AdjList[id].push_back(tmp);
            }
        }

        scanf("%d",&query);
        printf("-----\n");
        while(query--){
            scanf("%d %d",&src,&desc);
            src--,desc--;
            map <int,int> dist; dist[src]=0;
            queue <int> q; q.push(src);
            p.assign(n,0);
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int j=0;j<(int)AdjList[u].size();j++){
                    int tmp=AdjList[u][j];
                    if(!dist.count(tmp)){
                        dist[tmp]=dist[u]+1;
                        p[tmp]=u;
                        q.push(tmp);
                    }
                }
            }
            if(!dist.count(desc)) printf("connection impossible\n");
            else printPath(desc),printf("\n");
        }
    }
    return 0;
}
