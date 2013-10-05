#include <cstdio>
#include <cmath>

int main(){
  long long int a,b;
  while(scanf("%lld",&a)){
    if(a==0) break;
    b=sqrt(a);
    if(a==b*b) printf("yes\n");
    else  printf("no\n");
  }
  return 0;
}
