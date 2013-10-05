#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define INF -1000000000

int main(){
    int Graph[110][110],U,V,D,C,S,cas=0;
    while(scanf("%d %d",&C,&S),(C||S)){

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
              if(Graph[i][k]!=INF)
               for(int j=0;j<C;j++)
                  if(Graph[k][j]!=INF && i!=j)
                  Graph[i][j]=max(Graph[i][j],min(Graph[i][k],Graph[k][j]));

        scanf("%d %d %d",&U,&V,&D);
        U--; V--;
        printf("Scenario #%d\n",++cas);
        printf("Minimum Number of Trips = %d\n",(int)ceil(D*1.0/(Graph[U][V]-1)));
        printf("\n");
    }
    return 0;
}

