#include <cstdio>

int main(){
      int n;
      while(scanf("%d",&n)){
        if(n==0) break;
        int sum=0,tmp;

        while(n>=3)
          sum+=(n/3),n=(n/3)+n%3;
        if(n==2) sum++;

        printf("%d\n",sum);
      }
      return 0;
}


