#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define PI acos(-1)

int main(){
 int n,cnt=0;
 double area,theta,area_t,in,out;
 while(scanf("%d %lf",&n,&area)){
    if(n<3) break;
    theta=2.0*PI/n;
    area_t=area/n;
    out=sqrt(2.0*area_t/sin(theta));
    in=out*cos(theta/2.0);
    printf("Case %d: %0.5lf %0.5lf\n",++cnt,out*out*PI-area,area-in*in*PI);
 }
 return 0;
}
