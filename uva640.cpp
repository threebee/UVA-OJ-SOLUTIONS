#include <cstdio>
#include <bitset>
using namespace std;
#define MAX 1000000
typedef long long int lli;

bitset <1000010> bs;

void generator(){
    int i,j;
    lli sum;
    for(i=0;i<=MAX;i++){
      sum=i; j=i;
      for(;j>9;j/=10) sum+=j%10;
      sum+=j;
      bs[sum]=0;
    }
}

int main(){
    //freopen("output.txt","w",stdout);
    bs.set();
    generator();
    for(lli i=0;i<=MAX;i++)
      if(bs[i])
        printf("%lld\n",i);
    return 0;
}
