#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lli long long int

lli memo[110][110];
char str[70];

lli edit(int i,int j){
    if(i>j) return 1;
    if(memo[i][j]!=-1) return memo[i][j];
    else return memo[i][j]=edit(i,j-1)+edit(i+1,j)-(str[i]!=str[j])*edit(i+1,j-1);
}

int main(){
  int t,i,j,k;
  scanf("%d",&t);
  getchar();
  while(t--){
     gets(str);
     memset(memo,-1,sizeof memo);
     lli ans=edit(0,strlen(str)-1);
     printf("%lld\n",ans-1);
  }

  return 0;
}
