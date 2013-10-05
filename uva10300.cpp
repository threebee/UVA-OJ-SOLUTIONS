#include <cstdio>

int main(){
   int t,n,a,b,c;
   long total;
   scanf("%d",&t);
   while(t--){
    total=0;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&a,&b,&c);
        total+=(a*c);
    }
    printf("%ld\n",total);
   }
   return 0;
}
