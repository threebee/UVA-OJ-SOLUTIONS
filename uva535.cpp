#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#define PI 3.141592653589793
#define radius 6378

struct point{  double x,y;  };

map <string,point> mp;

double gcDistance(double pLat, double pLong,double qLat, double qLong) {
    pLat*=PI/180; pLong*=PI/180; qLat*=PI/180; qLong*=PI/180;
    double a= cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
           cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
           sin(pLat)*sin(qLat);
    if(a>1.) a=1.;              //limit of acos()
    if(a<-1.) a=-1.;            //limit of acos()
    return acos(a)*radius;
}

int main(){
 string temp,temp1;
 point p,p1;
 while(cin>>temp){
    if(temp=="#") break;
    cin>>p.x>>p.y;
    mp[temp]=p;
 }
 while(cin>>temp>>temp1){
    if(temp=="#" && temp1=="#") break;
    cout<<temp<<" - "<<temp1<<endl;
    if(!mp.count(temp) || !mp.count(temp1)){
        cout<<"Unknown\n";
        continue;
    }
    p=mp[temp];
    p1=mp[temp1];
    printf("%.0f km\n",gcDistance(p.x,p.y,p1.x,p1.y));
 }
 return 0;
}
