#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

#define INF 1000000000

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int K,M;
    double Graph[110][110];
    while(scanf("%d %d",&K,&M)==2){
        int x[110],y[110],r[110],n;
        scanf("%d %d %d",&x[0],&y[0],&r[0]);
        scanf("%d %d %d",&x[1],&y[1],&r[1]);
        scanf("%d",&n);
        n+=2;
        for(int i=2;i<n;i++)
            scanf("%d %d %d",&x[i],&y[i],&r[i]);
        double dist;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            dist=sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) );
            if(dist<r[i]+r[j]) dist=0;
            else  dist=dist-r[i]-r[j];

            if(dist > K*M) Graph[i][j]=INF;
            else           Graph[i][j]=dist;
        }

        for(int k=0;k<n;k++)
          for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(Graph[i][j] > Graph[i][k]+Graph[k][j])
                   Graph[i][j]=Graph[i][k]+Graph[k][j];

        if(Graph[0][1]==INF)
            printf("Larry and Ryan will be eaten to death.\n");
        else
            printf("Larry and Ryan will escape!\n");
    }
    return 0;
}
