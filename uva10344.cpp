#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int operate(int a,int b,int op){
    switch(op){
        case 0: return a+b;
        case 1: return a-b;
        case 2: return a*b;
    }
}


int main(){
  int in[5],i,j,a,b,c,d,sum;
  bool flag;

  while(scanf("%d %d %d %d %d",&in[0],&in[1],&in[2],&in[3],&in[4]),(in[0] || in[1] || in[2] || in[3] || in[4])){
      flag=false;
      sort(in,in+5);
      do{
        for(a=0;a<3;a++) for(b=0;b<3;b++)
        for(c=0;c<3;c++) for(d=0;d<3;d++){
            sum=in[0];
            sum=operate(sum,in[1],a);
            sum=operate(sum,in[2],b);
            sum=operate(sum,in[3],c);
            sum=operate(sum,in[4],d);
            if(sum==23) flag=true;
        }
        if(flag) break;
      }while(next_permutation(in,in+5));

      if(flag) printf("Possible\n");
      else     printf("Impossible\n");
  }
  return 0;
}
