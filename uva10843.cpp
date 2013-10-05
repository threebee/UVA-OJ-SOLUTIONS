#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define MOD 2000000011
typedef long long int lli;

int main(){
  lli t,n,i,cas=0,ans;
  scanf("%lld",&t);
  while(t--){
    scanf("%lld",&n);
    ans=1;
    for(i=0;i<n-2;i++)
      ans=((ans%MOD)*(n%MOD))%MOD;
    ans%=MOD;
    printf("Case #%lld: %lld\n",++cas,ans);
  }
  return 0;
}
