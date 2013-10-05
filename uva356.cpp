#include <cstdio>

int main(){

  int n,i,j,count1,count2;
  while(scanf("%d",&n)!=EOF){
     double r=(2*n - 1)/(double)2;
     count1=count2=0;
     for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
        if((i*i+j*j)<(r*r)) count1++;
     printf("In the case n = %d, %d cells contain segments of the circle. There are %d cells completely contained in the circle.\n\n",n,n*8-4,4*count1);

  }
  return 0;

}
