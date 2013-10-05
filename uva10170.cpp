#include<stdio.h>

int main(){
    long long int days,s,d,i;
    while(scanf("%lld %lld",&s,&d)==2){
         days=0;
         for(; ;){
            days=days+s;
            if(days>=d) break;
            else s=s+1;
         }
        printf("%lld\n",s);
    }
    return 0;
}
