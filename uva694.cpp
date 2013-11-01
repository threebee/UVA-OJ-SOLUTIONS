#include <cstdio>
typedef long long int lli;

int main(){
    lli a,limit,tmp,counter,cas=0;
    while(scanf("%lld %lld",&a,&limit)){
        if(a<0 && limit<0) break;
        counter=0;
        tmp=a;
        while(a<=limit){
            counter++;
            if(a==1) break;

            if(a & 1) a=3*a+1;
            else      a>>=1;
        }
        printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n",++cas,tmp,limit,counter);
    }
    return 0;
}
