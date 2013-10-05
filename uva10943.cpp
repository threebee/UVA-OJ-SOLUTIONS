#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MOD 1000000
int memo[105][105];

int ways(int n,int k){
    if(n<0 || k<0) return 0;
    if(memo[n][k]!=-1) return memo[n][k];
    int res=0;
    for(int i=0;i<=n;i++)
        res=((res%MOD)+(ways(n-i,k-1)%MOD))%MOD;
    return memo[n][k]=res%MOD;
}

int main(){
  int n,k;
  memset(memo,-1,sizeof memo);
  memo[0][0]=1;
  while(scanf("%d %d",&n,&k)){
    if(n==0 && k==0) break;
    printf("%d\n",ways(n,k));
  }
  return 0;
}
