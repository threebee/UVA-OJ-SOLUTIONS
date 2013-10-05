#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct slot{ int n,d,p; }s[1010];

bool cmp(slot a,slot b){
    if(a.d*b.p == b.d*a.p) return a.n < b.n;
    return a.d*b.p < b.d*a.p;
}

int main(){
   int t,n,i;
   bool flag=false;
   scanf("%d",&t);
   while(t--){
       scanf("%d",&n);
       for(i=0;i<n;i++) scanf("%d %d",&s[i].d,&s[i].p),s[i].n=i+1;
       sort(s,s+n,cmp);
       if(flag) printf("\n"); flag=true;
       for(i=0;i<n-1;i++) printf("%d ",s[i].n);
       printf("%d\n",s[i].n);
      // if(t) printf("\n");
   }
   return 0;
}
