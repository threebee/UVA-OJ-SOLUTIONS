/*
-->prince and princess
-->LCS to LIS then nlogk algorithm to compute answer
*/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn=250*250+10;
#define INF 2147483640

int b[maxn],c[maxn];

int main(){
 int t,counts=0,i,j,k,n,m,ct;
 scanf("%d",&t);
 while(t--){
   ct=0;
   memset(c,0,sizeof c);
   scanf("%d %d %d",&k,&n,&m);
   for(i=1;i<=n+1;i++){
       scanf("%d",&k); c[k]=i;
   }
   for(i=1;i<=m+1;i++){
       scanf("%d",&k);
       if(c[k])
         b[ct++]=c[k];
   }
   vector <int> d(ct+1);
   d[0]=-INF;
   for(i=1;i<=ct;i++) d[i]=INF;
   int maxi=0;
   for(i=0;i<ct;i++){
       j=int(upper_bound(d.begin(),d.end(),b[i])-d.begin());
       if(d[j-1]<b[i] && b[i]<d[j])
            d[j]=b[i];
       if(maxi<j) maxi=j;
   }
   printf("Case %d: %d\n",++counts,maxi);
 }
 return 0;
}
