/*
  Note that the circle with diameter of the polygon does not
  always enclose the polygon!
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

struct points { double x,y; };

double dist(points p1, points p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

bool circle2PtsRad(points p1, points p2, double r, points *c) {
  double d2 = (p1.x - p2.x) * (p1.x - p2.x) +
              (p1.y - p2.y) * (p1.y - p2.y);
  double det = r * r / d2 - 0.25;
  if (det < 0.0) return false;
  double h = sqrt(det);
  c->x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
  c->y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
  return true;
}

int main(){
  int i,j,k,n;
  double d;
  points p1;
  while(scanf("%d",&n),n){
        vector <points> input(n);
        for(i=0;i<n;i++) cin>>input[i].x>>input[i].y;
        cin>>d;
        bool flag=false;
        for(i=0;i<n;i++) for(j=0;j<n;j++) if(i!=j){
           circle2PtsRad(input[i],input[j],d,&p1);
           for(k=0;k<n;k++){
              if(dist(input[k],p1) > d) break;
           }
           if(k==n) flag=true;
        }
        if(flag) printf("The polygon can be packed in the circle.\n");
        else     printf("There is no way of packing that polygon.\n");
  }
  return 0;
}
