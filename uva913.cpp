#include <cstdio>

int main(){
 long long int k;
 while(scanf("%lld",&k)!=EOF){
   long long int n=((k-1)/2)+1;
   n=n*n;
   printf("%lld\n",(n*n)-((n-3)*(n-3)));
 }
 return 0;
}
