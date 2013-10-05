#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int a[1100],b[1100],n,m;
int memo[1100][1100];

int lcs(int i,int j){
    if(i<0 || j<0) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    if(a[i]==b[j]) return memo[i][j]=lcs(i-1,j-1)+1;
    else           return memo[i][j]=max(lcs(i-1,j),lcs(i,j-1));
}

int main(){
 int i,j,k,counts=0;
 while(scanf("%d %d",&n,&m)){
    if(n==0 && m==0) break;
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    for(i=0;i<m;i++) scanf("%d",&b[i]);
    memset(memo,-1,sizeof memo);
    printf("Twin Towers #%d\nNumber of Tiles : %d\n\n",++counts,lcs(n-1,m-1));
 }
 return 0;
}

