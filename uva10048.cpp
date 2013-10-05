#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define INF 1000000000

int main(){
    bool blank=false;
    int Graph[110][110],U,V,D,C,S,Q,cas=0;
    while(scanf("%d %d %d",&C,&S,&Q),(C||S||Q)){

        for(int i=0;i<C;i++) for(int j=0;j<C;j++){
            if(i==j) Graph[i][j]=0;
            else     Graph[i][j]=INF;
        }

        for(int i=0;i<S;i++){
            scanf("%d %d %d",&U,&V,&D);
            U--; V--;
            Graph[U][V]=Graph[V][U]=D;
        }

        for(int k=0;k<C;k++)
            for(int i=0;i<C;i++)
               for(int j=0;j<C;j++)
                  Graph[i][j]=min(Graph[i][j],max(Graph[i][k],Graph[k][j]));

        if(blank) printf("\n"); blank=true;
        printf("Case #%d\n",++cas);
        while(Q--){
            scanf("%d %d",&U,&V);
            U--; V--;
            if(Graph[U][V]!=INF) printf("%d\n",Graph[U][V]);
            else                 printf("no path\n");
        }
    }
    return 0;
}

