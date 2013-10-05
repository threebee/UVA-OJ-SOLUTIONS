#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;

#define PI acos(-1)
#define radius 6371009


double gcDistancetheta(double pLat, double pLong,double qLat, double qLong) {
    pLat*=PI/180; pLong*=PI/180; qLat*=PI/180; qLong*=PI/180;
    return acos(cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
           cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
           sin(pLat)*sin(qLat));
}

int main(){
 int t;
 double ax,ay,bx,by;
 scanf("%d",&t);
 while(t--){
    cin>>ax>>ay>>bx>>by;
    double theta=gcDistancetheta(ax,ay,bx,by);
    double beta=2*sin(theta/2);
    printf("%.0lf\n",round(radius*(theta-beta)));
 }
 return 0;
}
