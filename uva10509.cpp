#include <cstdio>
#include <cmath>
#define EPS 1e-6

int main(){
 int i;
 double f,dx,n=(1.0/3);
 while(scanf("%lf",&f) && f){
     i=pow(f+EPS,n);
     dx=(f-i*i*i)/(3*i*i);
     printf("%0.4lf\n",dx+i);
 }
 return 0;
}
