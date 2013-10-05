#include <cstdio>

int main(){
    long long n;
    while(scanf("%lld",&n)){
        if(n<0) break;
        if(n==1) printf("0%%\n");
        else printf("%lld%%\n",25*n);
    }
    return 0;
}
