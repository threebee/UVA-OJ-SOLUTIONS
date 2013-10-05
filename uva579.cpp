#include <cstdio>
#include <cmath>

int main(){
 int a,b;
 while(scanf("%d%*c%d",&a,&b)){
 if(a==0 && b==0) break;
 float ans=0.5*((60*a)+b),ans1=6*b;
 ans=fabs(ans-ans1);
 if(ans>180) ans=360-ans;
 printf("%0.3f\n",ans);
 }
 return 0;
}
