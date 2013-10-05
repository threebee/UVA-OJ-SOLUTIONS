#include <iostream>
#include <cstdio>
using namespace std;
#define MOD 1000000

int main(){
  int n,i;
  long long int fac;
    while(scanf("%d",&n)==1){
        fac=1;
        for(i=2;i<=n;i++){
            fac*=i;
            if(fac%10 == 0){
                while(fac%10 == 0) fac/=10;
            }
            fac=fac%MOD;
        }
        printf("%5d -> %d\n",n,fac%10);
    }
    return 0;
}
