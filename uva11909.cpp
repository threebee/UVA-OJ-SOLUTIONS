#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define PI acos(-1)

int main(){
  int l,w,h,theta;
  double ang;
  while(scanf("%d %d %d %d",&l,&w,&h,&theta)==4){
      ang=l*tan(theta*PI/180.0);
      if(ang>h)
        printf("%0.3lf mL\n",0.5*h*h*w/tan(theta*PI/180.0));
      else
        printf("%0.3lf mL\n",l*h*w - 0.5*l*ang*w);
  }
  return 0;
}
