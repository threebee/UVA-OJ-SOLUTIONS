#include <cstdio>
#include <cmath>

#define isPowerofTwo(x) ((x & (x-1))==0)
#define nearestPowerofTwo(x) ((int)pow(2.0,(int)(log((double)x)/log(2.0))))

int main(){
 int n;
 while(scanf("%d",&n)){
    if(n==0) break;
    if(isPowerofTwo(n)) printf("%d\n",n);
    else printf("%d\n",(n-nearestPowerofTwo(n))*2);
 }
 return 0;
}
