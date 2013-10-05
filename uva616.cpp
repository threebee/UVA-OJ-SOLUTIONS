#include <cstdio>
#include <cmath>

int main(){

    int n,i,flag,temp,t,k,counts,s;

    while(scanf("%d",&n)){

        if(n<0) break;

        flag=0,temp=0;
        t=n,k=n;
        s=sqrt(k)+1;
        for(i=s;i>=2;i--){
            n=t;
            counts=0;
            if(n%i==1){
               while(n%i==1){
                 n=n-(n/i)-1;
                 counts++;
               }
               if(n%i==0 && counts==i) {
                  flag=1;
                  temp=i;
               }
               if(flag) break;
            }
        }
        if(temp)
        printf("%d coconuts, %d people and 1 monkey\n",k,temp);
        else
        printf("%d coconuts, no solution\n",k);
    }

  return 0;
}
