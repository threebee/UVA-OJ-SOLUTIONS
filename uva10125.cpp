#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define lli long long int

lli arr[1010];

int main(){
  int n,i,j,k,pos,d;
  lli sum,maxi;
  while(scanf("%d",&n),n){
      for(i=0;i<n;i++) scanf("%lld",&arr[i]);
      sort(arr,arr+n);
      maxi=INT_MAX;
      bool flag=false;
      for(d=n-1;d>=0;--d){
            for(i=0;i<n;++i){
                for(j=i+1;j<n;++j){
                    for(k=j+1;k<n;++k){
                        if(arr[d]==arr[i]+arr[j]+arr[k] && i!=d && j!=d && k!=d){
                             maxi=arr[d]; flag=true; break;
                        }
                    }
                    if(flag) break;
                }
                if(flag) break;
            }
            if(flag) break;
      }
     if(maxi==INT_MAX) printf("no solution\n");
     else  printf("%lld\n",maxi);
  }
  return 0;
}
