/*
  ALL PAIRS SHORTEST PATH
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
#define INF 1000000000

int main(){
    int n,mat[110][110];
    string tmp;
    scanf("%d",&n);
    memset(mat,0,sizeof mat);
    for(int i=1;i<n;i++)
    for(int j=0;j<i;j++){
        cin>>tmp;
        if(tmp=="x") mat[i][j]=INF,mat[j][i]=INF;
        else          mat[i][j]=mat[j][i]=atoi(tmp.c_str());
    }

    for(int k=0;k<n;k++)
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);

    int ans=0;
    for(int i=0;i<n;i++)
        ans=max(ans,mat[i][0]);

    printf("%d\n",ans);

    return 0;
}
