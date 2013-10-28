#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    long long int m[100],f[100];
    m[0]=0; m[1]=1;
    f[0]=1; f[1]=1;
    for(int i=2;i<100;i++){
        m[i]=m[i-2]+m[i-1]+1;
        if(m[i]<0) break;
    }
    for(int i=2;i<100;i++){
        f[i]=f[i-1]+f[i-2];
        if(f[i]<0) break;
    }

    int n;
    while(scanf("%d",&n),(n>-1)){
        printf("%lld %lld\n",m[n],f[n+2]-1);
    }
    return 0;
}
