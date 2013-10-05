#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define INF 1000000000

int main(){
    int t,n,x[110],y[110],cas=0;
    double Graph[110][110];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&x[i],&y[i]);

        int dist;
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            dist=((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));

            if(dist > 100) Graph[i][j]=INF;
            else           Graph[i][j]=sqrt((double)dist);
        }

        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
               for(int j=0;j<n;j++)
                  if(Graph[i][j] > Graph[i][k] + Graph[k][j])
                    Graph[i][j]=Graph[i][k]+Graph[k][j];

        double maxi=0.0;
        for(int i=0 ;i<n;i++)
          for(int j=0;j<n;j++)
            maxi = max(maxi,Graph[i][j]);

        printf("Case #%d:\n",++cas);
        if(maxi==INF) printf("Send Kurdy\n");
        else          printf("%0.4lf\n",maxi);
        printf("\n");
    }
    return 0;
}
