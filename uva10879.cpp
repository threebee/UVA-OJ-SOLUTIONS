#include <cstdio>

int main(){
    int t;
    scanf("%d",&t);
    for(long long int i=1;i<=t;i++){
        long long int k,a[4],cou=0,j=2;
        scanf("%lld",&k);
        while(cou<3){
        if(k%j==0){
            a[cou++]=j;
            a[cou++]=k/j;
        }
        j++;
        }
    printf("Case #%lld: %lld = %lld * %lld = %lld * %lld\n",i,k,a[0],a[1],a[2],a[3]);
    }
    return 0;
}
