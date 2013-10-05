/*
 algorithm -> greedy
 difference of absolute sums
 5 -4  1 -3  1
 5  5  6  6  7 -> sum of positve numbers
 0  4  4  7  7 -> absolute sum of negative numbers
 --------------
 5  1  2  1  0 -> 9 sum of absolute difference
*/

#include <cstdio>
typedef long long int lli;

lli abs(lli a){
    if(a>0) return a;
    return -a;
}

int main(){
  int i,n,input;
  long long int ans,pos,neg;
  while(scanf("%d",&n),n){
      pos=0,neg=0,ans=0;
      for(i=0;i<n;i++){
        scanf("%d",&input);
        if(input<0) neg+=(-1*input);
        else        pos+=input;
        ans+=abs(neg-pos);
      }
      printf("%lld\n",ans);
  }
  return 0;
}
