#include <cstdio>
#define MAX 32000

int main(){
  int coins[11]={10000,5000,2000,1000,500,200,100,50,20,10,5};
  long long int p[MAX+1];
  p[0]=1;
  for(int i=0;i<11;i++)
   for(int j=coins[i];j<=MAX;j++)
      p[j]=p[j]+p[j-coins[i]];

  int input,p1,p2;
  char c;

  while(scanf("%d %c %d",&p1,&c,&p2)==3){
    if(p1==0 && p2==0) break;
    input=p1*100+p2;
    printf("%6.2f%17lld\n",((float)input/100.0f),p[input]);
  }
  return 0;
}
