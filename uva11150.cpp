#include <cstdio>

int main(){
 int n;
 while(scanf("%d",&n)!=EOF){
    int sum=n,tmp,borrow=0,cou=0;
    while(n>=2){
       if((n+1)%3==0 && borrow==0){
            borrow=1;
            n=n+1;
            tmp=n%3;
            sum+=(n/3);
            n=(n/3)+tmp;
       }
       else{
           tmp=n%3;
           sum+=(n/3);
           n=(n/3)+tmp;
       }
       cou++;
       if(cou>20) break;
    }
    printf("%d\n",sum);
 }
 return 0;
}

