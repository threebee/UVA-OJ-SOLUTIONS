#include <iostream>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
  int m,n,t,ans[10010],i;
  while(scanf("%d %d %d",&m,&n,&t)==3){
        memset(ans,0,sizeof ans);
        if(m<=t) ans[m]=1;
        if(n<=t) ans[n]=1;
        for(i=min(m,n);i<=t;i++)
            if(ans[i]){
               if(i+n<=t)   ans[i+n]=max(ans[i+n],ans[i]+1);
               if(i+m<=t)   ans[i+m]=max(ans[i+m],ans[i]+1);
            }
        if(ans[t]){
            printf("%d\n",ans[t]);
            continue;
        }
        i=t-1;
        while(!ans[i] && i>0) i--;
        printf("%d %d\n",ans[i],t-i);
  }
  return 0;
}
