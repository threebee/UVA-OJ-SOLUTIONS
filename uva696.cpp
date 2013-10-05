#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int n,m,a,b;
    while(scanf("%d %d",&n,&m),(n||m)){
        a=n,b=m;
        if(n>m) swap(n,m);
        if(n==1)        printf("%d knights may be placed on a %d row %d column board.\n",m,a,b);
        else if(n==2)   printf("%d knights may be placed on a %d row %d column board.\n",m/4 * 4 + (m%4 == 1 ? 2 : (m % 4 >= 2? 4 : 0)),a,b);
        else            printf("%d knights may be placed on a %d row %d column board.\n",(n*m+1)/2,a,b);
    }
    return 0;
}
