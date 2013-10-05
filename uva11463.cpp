#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define INF 1000000000
int mat[110][110];

int main(){
    int t,n,r,cas=0,s,d;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&r);

        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
           mat[i][j]=INF;

        for(int i=0;i<n;i++) mat[i][i]=0;
        int a,b;
        while(r--){
            scanf("%d %d",&a,&b);
            mat[a][b]=mat[b][a]=1;
        }

        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);

        scanf("%d %d",&s,&d);

        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,mat[s][i]+mat[i][d]);

        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}
