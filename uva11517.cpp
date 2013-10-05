#include <cstdio>
#include <cstring>
#include <iostream>
#include <cctype>
#include <climits>
using namespace std;

int main(){
 int t,sum,coins[110],dp[10010],n,i,j;
 scanf("%d",&t);
 while(t--){
   scanf("%d",&sum);
   scanf("%d",&n);
   for(i=0;i<n;i++) scanf("%d",&coins[i]);
    for(i=0;i<10010;i++) dp[i]=INT_MAX;
    dp[0]=0;
    for(i=0;i<n;i++)
    for(j=10000;j>=0;j--){
        if(dp[j]!=INT_MAX && j+coins[i]<=10000 && dp[j+coins[i]]>dp[j]+1)
             dp[j+coins[i]]=dp[j]+1;
    }
    for(i=sum;i<=10000;i++)
    if(dp[i]!=INT_MAX){
        printf("%d %d\n",i,dp[i]);
        break;
    }
 }
 return 0;
}
