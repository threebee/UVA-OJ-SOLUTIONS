#include <cstdio>
#include <cmath>

int main(){
 double p,n;
 while(scanf("%lf %lf",&p,&n)!=EOF){
     printf("%0.lf\n",pow(n,1/p));
 }
 return 0;
}
