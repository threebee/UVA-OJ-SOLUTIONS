#include <cstdio>
#include <cmath>

int main(){
 int l,f;
 while(scanf("%d %d",&l,&f)){
    if(l+f==0) break;
    double v=sqrt(2*l*f);
    double volume=v*1800/l;
    printf("%0.8lf %0.8lf\n",v,volume);
 }
 return 0;
}
