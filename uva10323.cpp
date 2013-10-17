/*
 wrong logic
 -1 = 1/0 = +infinty (overflow)
 -2 = -1!/-1 = +infinity (underflow)
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
        if(n<0){
          n=-n;
          if(n%2==1) printf("Overflow!\n");
          else       printf("Underflow!\n");
          continue;
        }
        if(n<8){
          printf("Underflow!\n");
          continue;
        }
        if(n>13){
          printf("Overflow!\n");
          continue;
        }

        long long int res=40320;
        for(int i=9;i<=n;i++) res=res*i;
        printf("%lld\n",res);
    }
    return 0;
}
