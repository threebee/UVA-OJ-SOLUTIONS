/*
  concepts used->
  1. modular inverse
  2. sieve (modified)
  3. russian peasent

  for ans-
    ->first nullify effect of factor
    ->then modify power of factor
    ->multiply effect of factor

  yeah!! :D just do it
*/

#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define mx  1000000
#define mod 1000000007
#define ll long long int

bool  v[1000010];
ll   pd[1000010],fact[1000010],ans,r;

void sieve(){
    for(ll i=2; i<=mx; i+=2) pd[i]=2;
    for(ll i=3; i<=mx; i+=2){
        if(!v[i]){
            pd[i]=i;
            for(ll j=i;(j*i)<=mx; j+=2){
                v[j*i]=true;
                pd[j*i]=i;
            }
        }
    }
}

int modI(ll a,ll b){
    r=1;
    while(b){
        if(b & 1) r=(a*r)%mod;
        b=b>>1;
        a=(a*a)%mod;
    }
}

ll cal(ll n,bool flag){
    while (n != 1){
        ll cnt=0,s=pd[n];
        while((n%s)==0) n/=s, cnt++;
        modI((fact[s]+1),mod-2);
        ans=(ans*r)%mod;
        if(flag) fact[s]-=cnt;
        else     fact[s]+=cnt;
        ans=(ans*(fact[s]+1))%mod;
    }
    return ans;
}

int main(){
    sieve();
    int t,cnt=0;
    ll n,sum,d;
    scanf("%d",&t);
    while(t--){
        memset(fact,0,sizeof fact);
        sum=0,ans=1;
        scanf("%lld",&d);
        while(d--){
            scanf("%lld",&n);
            if(n<0)  sum=(sum+cal(-n,true))%mod;
            else     sum=(sum+cal(n,false))%mod;
        }
        printf("Case %d: %lld\n",++cnt,sum);
    }
    return 0;
}
