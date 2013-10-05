#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
#define INF 1000000000

int main(){
    int n,m,N,mat[110][110],counts,cas=0;
    map <int,int> mp;
    while(scanf("%d %d",&n,&m),(n||m)){
        N=0; counts=0;
        mp.clear();
        if(!mp.count(n)) mp[n]=counts++;
        if(!mp.count(m)) mp[m]=counts++;
        N=max(N,max(n,m));

        for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
           mat[i][j]=INF;

        for(int i=0;i<=100;i++) mat[i][i]=0;

        mat[n][m]=1;
        while(scanf("%d %d",&n,&m),(n||m)){
             N=max(N,max(n,m));
             mat[n][m]=1;
             if(!mp.count(n)) mp[n]=counts++;
             if(!mp.count(m)) mp[m]=counts++;
        }

        for(int k=1;k<=N;k++)
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);

        int sum=0;
        for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(mat[i][j]!=INF) sum+=mat[i][j];

        printf("Case %d: average length between pages = %0.3f clicks\n",++cas,sum/(float)(counts *(counts-1)));
    }
    return 0;
}
