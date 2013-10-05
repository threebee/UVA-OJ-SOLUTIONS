#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
#define EPS 1e-9

struct point { double x,y; };

double dist(point p1, point p2) {
  return hypot(p1.x - p2.x, p1.y - p2.y);
}

double distToLine(point p, point A, point B, point *c) {
  double scale = (double)
    ((p.x - A.x) * (B.x - A.x) + (p.y - A.y) * (B.y - A.y)) /
    ((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y));
  c->x = A.x + scale * (B.x - A.x);
  c->y = A.y + scale * (B.y - A.y);
  return dist(p, *c);
}

double distToLineSegment(point p, point A, point B, point* c) {
  if ((B.x-A.x) * (p.x-A.x) + (B.y-A.y) * (p.y-A.y) < EPS) {
    c->x = A.x;   c->y = A.y;
    return dist(p, A); }
  if ((A.x-B.x) * (p.x-B.x) + (A.y-B.y) * (p.y-B.y) < EPS) {
    c->x = B.x;   c->y = B.y;
    return dist(p, B); }
  return distToLine(p, A, B, c);
}

int main(){
  point p;
  int n,i,j;
  while(scanf("%lf",&p.x)==1){
     scanf("%lf",&p.y);
     scanf("%d",&n);
     point x[n+1];
     for(i=0;i<n+1;i++) scanf("%lf %lf",&x[i].x,&x[i].y);
     double min_dist=(double)INT_MAX,dist;
     point ans,temp;
     for(i=0;i<n;i++){
        dist=distToLineSegment(p,x[i],x[i+1],&temp);
        if(dist<min_dist){
            min_dist=dist;
            ans=temp;
        }
     }
     printf("%0.4lf\n%0.4lf\n",ans.x,ans.y);
  }
  return 0;
}
