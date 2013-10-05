#include <cstdio>

int main(){
 int n,k;
 while(scanf("%d %d",&n,&k)!=EOF){
    int sum=n,tmp;
    while(n>=k){
        tmp=n%k;
        sum+=(n/k);
        n=(n/k)+tmp;
    }
    printf("%d\n",sum);
 }
 return 0;
}
