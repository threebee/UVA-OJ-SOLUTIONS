#include <cstdio>
#include <cmath>

int main(){
 int t,n;
 double s=sqrt(2);
 scanf("%d",&t);
 while(t--){
    scanf("%d",&n);
    if(n>1) printf("%0.3lf\n",(4*n -4)+s*(n-2)*(n-2));
    else    printf("0.000\n");
 }
 return 0;
}
