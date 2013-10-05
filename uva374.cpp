#include <iostream>
#include <cstdio>
using namespace std;
#define lli long long int
/*
lli bigmod(lli b,lli p,lli m){
    if(p==0) return 1;
    if(p==1) return b;
    if(p%2==0) {
        b=((b%m)*(b%m))%m;
        return bigmod(b,p/2,m)%m;
    }
    else  return (b*bigmod(b,p-1,m))%m;
}
*/
lli r;

lli bigmod(lli a,lli b,lli mod){
    r=1;
    while(b){
        if(b & 1) r=(a*r)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
    return r;
}

int main(){
    lli b,p,m;
    while(scanf("%lld %lld %lld",&b,&p,&m)==3){
        printf("%lld\n",bigmod(b,p,m));
    }
}
