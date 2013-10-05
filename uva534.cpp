#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
#define INF 1000000000

vector <int> vx,vy;

int main(){
    double Graph[210][210];
    int C,a,b,cas=0;
    while(scanf("%d",&C),C){

        for(int i=0;i<C;i++) for(int j=0;j<C;j++){
            if(i==j) Graph[i][j]=0;
            else     Graph[i][j]=INF;
        }

        vx.clear(); vy.clear();
        for(int i=0;i<C;i++){
            scanf("%d %d",&a,&b);
            vx.push_back(a); vy.push_back(b);
        }

        for(int i=0;i<C;i++){
            for(int j=i+1;j<C;j++){
                double dist=sqrt( (vx[i]-vx[j])*(vx[i]-vx[j]) + (vy[i]-vy[j])*(vy[i]-vy[j]) );
                Graph[i][j]=Graph[j][i]=dist;
            }
        }

        for(int k=0;k<C;k++)
            for(int i=0;i<C;i++)
               for(int j=0;j<C;j++)
                  Graph[i][j]=min(Graph[i][j],max(Graph[i][k],Graph[k][j]));

        printf("Scenario #%d\n",++cas);
        printf("Frog Distance = %0.3lf\n",Graph[1][0]);
        printf("\n");
    }
    return 0;
}


