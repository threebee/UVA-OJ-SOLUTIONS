#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    long long int n,maxi;
    long long int a[101],b;
    while(1){
        scanf("%lld",&n);
        if(n==0) break;
        memset(a,0,sizeof(a));
        maxi=0;
        for(long long int i=0;i<n;i++){
            scanf("%lld",&b);
            a[b]++;
            if(b>maxi) maxi=b;
        }
       for(long long int i=1;i<maxi;i++){
           while(a[i]--)
           printf("%lld ",i);
       }
       while(a[maxi]!=1){
            printf("%lld ",maxi);
            a[maxi]--;
       }
       printf("%lld\n",maxi);
    }
 return 0;
}
