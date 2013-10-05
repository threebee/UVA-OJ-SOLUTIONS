#include <cstdio>

int main(){
 int t,i,j;
 scanf("%d",&t);
 while(t--){
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--){
      for(i=1;i<=n;i++){
          j=0;
          while(j<i){ printf("%d",i); j++; }
          printf("\n");
      }
      for(i=n-1;i>0;i--){
          j=0;
          while(j<i){ printf("%d",i); j++; }
          printf("\n");
      }
      if(m) printf("\n");
    }
    if(t) printf("\n");
 }
 return 0;
}
