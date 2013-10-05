#include <cstdio>
#include <cmath>
using namespace std;
#define PI acos(-1)

double perimeter(double ab, double bc, double ca) {
  return ab + bc + ca;
}

double area(double ab, double bc, double ca) {
  double s = 0.5 * perimeter(ab, bc, ca);
  return sqrt(s) * sqrt(s - ab) * sqrt(s - bc) * sqrt(s - ca);
}

double rInCircle(double ab, double bc, double ca) {
  return area(ab, bc, ca) / (0.5 * perimeter(ab, bc, ca));
}

double rCircumCircle(double ab, double bc, double ca) {
  return ab * bc * ca / (4.0 * area(ab, bc, ca));
}

int main(){
  int a,b,c;
  while(scanf("%d %d %d",&a,&b,&c)==3){
    double in=rInCircle(a,b,c);
           in=PI*in*in;
    double out=rCircumCircle(a,b,c);
           out=PI*out*out;
    double tri=area(a,b,c);
    printf("%0.4lf %0.4lf %0.4lf\n",out-tri,tri-in,in);
  }
  return 0;
}


