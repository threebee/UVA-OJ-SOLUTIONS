#include <cstdio>
#include <cstring>

int coins[5]={1,5,10,25,50};

int main(){
 long long int ans[8000];
 memset(ans,0,sizeof(ans));
 ans[0]=1;
 for(int i=0;i<5;i++)
    for(int j=coins[i];j<=8000;j++)
      ans[j]+=ans[j-coins[i]];
 int n;
 while(scanf("%d",&n)==1){
    printf("%lld\n",ans[n]);
 }
 return 0;
}
