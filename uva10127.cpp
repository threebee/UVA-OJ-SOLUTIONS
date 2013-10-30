#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int lli;

int main (){
    lli n,k,input,counts;
    while (scanf("%lld", &input)==1){
        n=k=counts=1;
        while(k){
            if(n<input){
                n=(n*10)+1;
                counts++;
            }
            k=n%input; n=k;
        }
        printf("%lld\n",counts);
    }
    return 0;
}
