#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n,cas=0;
    double u,v,a,t,s;
    while(scanf("%d",&n),n){
        printf("Case %d: ",++cas);
        switch(n){
            case 1:{
                     scanf("%lf %lf %lf",&u,&v,&t);
                     a=(v-u)/t;
                     s=u*t + 0.5*a*t*t;
                     printf("%0.3lf %0.3lf\n",s,a);
                   }
                   break;
            case 2:{
                     scanf("%lf %lf %lf",&u,&v,&a);
                     t=(v-u)/a;
                     s=u*t + 0.5*a*t*t;
                     printf("%0.3lf %0.3lf\n",s,t);
                   }
                   break;
            case 3:{
                     scanf("%lf %lf %lf",&u,&a,&s);
                     v=sqrt(2*a*s + u*u);
                     t=(v-u)/a;
                     printf("%0.3lf %0.3lf\n",v,t);
                   }
                   break;
            case 4:{
                     scanf("%lf %lf %lf",&v,&a,&s);
                     u=sqrt(v*v - 2*a*s);
                     t=(v-u)/a;
                     printf("%0.3lf %0.3lf\n",u,t);
                   }
                   break;
        }
    }
    return 0;
}
