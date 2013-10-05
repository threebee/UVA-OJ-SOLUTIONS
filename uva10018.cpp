#include <cstdio>
using namespace std;

int main(){
    long long int t,num,n,rev,counts,dig;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&num);
        counts=0;
        while(1){
            n=num;
            rev=0;
            while(num>0){
                dig=num%10;
                rev=rev*10+dig;
                num=num/10;
            }
            if(n==rev) break;
            counts++;
            num=n+rev;
        }
        printf("%lld %lld\n",counts,n);
    }
    return 0;
}
