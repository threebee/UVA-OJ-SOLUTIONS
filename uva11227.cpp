#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

#define EPS 1e-9

struct point { double x,y; };
vector <point> z;

double cross(point p, point q, point r) {
  return (r.x - q.x) * (p.y - q.y) - (r.y - q.y) * (p.x - q.x); }

bool collinear(point p, point q, point r) {
  return fabs(cross(p, q, r)) < EPS; }


int main(){
 int t,cnt=0,n,i,j,k;
 point tmp;
 bool flag;
 scanf("%d",&t);
 while(t--){
    z.clear();
    scanf("%d",&n);
    for(i=0;i<n;i++){
        flag=false;
        scanf("%lf %lf",&tmp.x,&tmp.y);
        for(j=0;j<z.size();j++){
            if(z[j].x==tmp.x && z[j].y==tmp.y){
                flag=true;
                break;
            }
        }
        if(flag) continue;
        z.push_back(tmp);
    }

    if(z.size()==1){
        printf("Data set #%d contains a single gnu.\n",++cnt);
        continue;
    }
    n=(int)z.size();
    int maxi=0,counts=0;
    for(i=0;i<n;i++)
    for(j=i+1;j<n;j++){
        counts=0;
     for(k=j+1;k<n;k++){
        if(collinear(z[i], z[j], z[k])) counts++;
     }
     if(counts>maxi) maxi=counts;
    }
    printf("Data set #%d contains %d gnus, out of which a maximum of %d are aligned.\n",++cnt,z.size(),maxi+2);
 }
 return 0;
}
