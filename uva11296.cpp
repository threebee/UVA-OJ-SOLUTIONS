#include <cstdio>

int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        long long s=(n/2)+1;
        printf("%lld\n",s*(s+1)/2);
    }
    return 0;
}
