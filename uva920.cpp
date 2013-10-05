#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

struct point { double x,y; };

struct line  { double a, b, c; };

line pointsToLine(point p1, point p2) {
  line l;
  if (p1.x==p2.x) { l.a = 1.0;   l.b = 0.0;   l.c =-p1.x; }
  else {
    l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
    l.b = 1.0;
    l.c = -(double)(l.a * p1.x) - (l.b * p1.y);
  }
  return l;
}

double getpoint(line l,double y){
    return  -(l.b*y + l.c)/l.a;
}

bool cmp(point a,point b){ return a.x<b.x; };

double dist(point p1, point p2){
    return hypot(p1.x - p2.x, p1.y - p2.y);
};

int main(){
 int t,n,i;
 scanf("%d",&t);
 while(t--){
    scanf("%d",&n);
    point p[n];
    for(i=0;i<n;i++){ cin>>p[i].x>>p[i].y; }
    sort(p,p+n,cmp);
    double h,distance=0;
    h=p[n-2].y;
    distance+=dist(p[n-1],p[n-2]);
    i=n-3;
    bool flag=false;
    line l;
    point temp;
    double x;
    int j;
    while(i>=0){
        for(j=i;j>=0;j--){
            if(h<p[j].y) break;
        }
        i=j;
        if(i<0) break;
        if(flag) break;
        l=pointsToLine(p[i],p[i+1]);
        x=getpoint(l,h);
        temp.x=x; temp.y=h;
        distance+=dist(p[i],temp);
        h=p[i].y;
    }
    printf("%0.2lf\n",distance);
 }
 return 0;
}
