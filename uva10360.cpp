#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int input[1030][1030];

int main(){
   int t,d,n,i,j,k,x,y,siz;
   scanf("%d",&t);
   while(t--){
       scanf("%d",&d);
       memset(input,0,sizeof input);
       scanf("%d",&n);
       for(i=0;i<n;i++){
           scanf("%d %d %d",&x,&y,&siz);
           for(j=max(0,x-d);j<=min(x+d,1024);j++)
             for(k=max(0,y-d);k<=min(y+d,1024);k++)
                input[j][k]+=siz;
       }
       int maxi=0;
       for(i=0;i<=1024;i++) for(j=0;j<=1024;j++)
          if(input[i][j]>maxi){
              maxi=input[i][j];
              x=i,y=j;
          }
       printf("%d %d %d\n",x,y,maxi);
   }
   return 0;
}
