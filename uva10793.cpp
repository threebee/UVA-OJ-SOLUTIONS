#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define INF 1000000000

int main(){
    int t,Graph[110][110],L,D,U,V,C,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&L,&D);

        for(int i=0;i<L;i++) for(int j=0;j<L;j++){
            if(i==j) Graph[i][j]=0;
            else     Graph[i][j]=INF;
        }

        for(int i=0;i<D;i++){
            scanf("%d %d %d",&U,&V,&C);
            U--; V--;
            if(C < Graph[U][V])
              Graph[U][V]=Graph[V][U]=C;
        }

        for(int k=0;k<L;k++)
            for(int i=0;i<L;i++)
               for(int j=0;j<L;j++)
                  if(Graph[i][j] > Graph[i][k]+Graph[k][j])
                     Graph[i][j]=Graph[i][k]+Graph[k][j];

        int maxi=INF;
        for(int i=0;i<L;i++){
            int tmp=Graph[i][0];
            int j;
            for(j=0;j<5;j++)
               if(tmp!=Graph[i][j]) break;
            if(j<5) continue;

            for(int k=1;k<L;k++)
                if(Graph[i][k] > tmp) tmp=Graph[i][k];

            if(tmp < maxi) maxi=tmp;
        }

        if(maxi==INF) printf("Map %d: -1\n",++cas);
        else          printf("Map %d: %d\n",++cas,maxi);

    }
    return 0;
}
