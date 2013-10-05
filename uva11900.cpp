#include <cstdio>

int main(){
 int t,i,j,n,p,q,arr[35],sum,cnt=0;
 scanf("%d",&t);
 while(t--){
    scanf("%d %d %d",&n,&p,&q);
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    sum=0;
    for(i=1;i<=n;i++){
        sum+=arr[i-1];
        if(sum>q || i>p) break;
    }
    printf("Case %d: %d\n",++cnt,i-1);
 }
 return 0;
}
