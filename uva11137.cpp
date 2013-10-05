#include <cstdio>
#include <cstring>
#define cube(x) x*x*x

int main(){
 long long int ans[10010];
 memset(ans,0,sizeof(ans));
 ans[0]=1;
 for(int i=1;i<=21;i++)
    for(int j=cube(i);j<=10010;j++)
      ans[j]+=ans[j-cube(i)];
 int n;
 while(scanf("%d",&n)==1){
    printf("%lld\n",ans[n]);
 }
 return 0;
}
