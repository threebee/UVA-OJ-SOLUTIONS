#include <cstdio>

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      int n,k,e;
      scanf("%d %d %d",&n,&e,&k);
      n+=e;
      int tmp2=n;
      int sum=n,tmp;
      while(n>=k){
        tmp=n%k;
        sum+=(n/k);
        n=(n/k)+tmp;
      }
      printf("%d\n",sum-tmp2);
    }
    return 0;
}

