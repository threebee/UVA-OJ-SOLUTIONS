#include <cstdio>
#define lli long long int

int main(){
 lli a,b,c,d,l;
 while(scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&l)){
    if(a==0 && b==0 && c==0 && d==0 && l==0) break;
    lli cou=0;
    for(lli i=0;i<=l;i++)
        if((a*i*i+b*i+c)%d == 0) cou++;
    printf("%lld\n",cou);
 }
 return 0;
}
