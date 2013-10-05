#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n),n){
        int sum;
        while(n>9){
            sum=0;
            while(n) sum+=n%10,n/=10;
            n=sum;
        }
        printf("%d\n",n);
    }
    return 0;
}
