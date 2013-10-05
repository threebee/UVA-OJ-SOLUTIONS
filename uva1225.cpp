#include <cstdio>
#include <cstring>

int main(){
 int i,t,n,cnt[10],tmp;
 scanf("%d",&t);
 while(t--){
    scanf("%d",&n);
    memset(cnt,0,sizeof cnt);
    for(i=1;i<=n;i++){
        tmp=i;
        while(tmp){
            cnt[tmp%10]++;
            tmp/=10;
        }
    }
    for(i=0;i<9;i++) printf("%d ",cnt[i]);
    printf("%d\n",cnt[9]);
 }
 return 0;
}
