#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define INF 2000000000
int input[55],memo[55][55];

int cal(int left,int right){
    if((left+1)==right) return 0;
    if(memo[left][right]!=-1) return memo[left][right];
    int ans=INF;
    for(int j=left+1;j<right;j++)
        ans=min(ans,cal(left,j)+cal(j,right)+(input[right]-input[left]));
    return memo[left][right]=ans;
}

int main(){
   int n,i,len;
   while(scanf("%d",&len),len){
       scanf("%d",&n);
       input[0]=0;
       for(i=1;i<=n;i++) scanf("%d",&input[i]);
       input[n+1]=len;
       memset(memo, -1, sizeof memo);
       printf("The minimum cutting is %d.\n",cal(0,n+1));
   }
   return 0;
}
