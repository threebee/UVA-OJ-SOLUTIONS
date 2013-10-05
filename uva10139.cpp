/*
  factorize m
  check for support in n!
  floor(n/m^1)+ floor(n/m^2)+ floor(n/m^3)+ floor(n/m^4)+....

*/

#include <iostream>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;


vector <int> primes;
bitset <10000010>  seive;

void cal_primes(int _size){
    seive.set();
    seive[0]=seive[1]=0;
    for(lli i=2;i<_size;i++) if(seive[i]){
        for(lli j=i*i;j<_size;j+=i) seive[j]=0;
        primes.push_back((int)i);
    }
}

vi primeFactors(lli N) {
  vi factors;
  lli PF_idx = 0, PF = primes[PF_idx];
  while (N != 1 && (PF * PF <= N)) {
    while (N % PF == 0) { N /= PF; factors.push_back(PF); }
    PF = primes[++PF_idx];
  }
  if (N != 1) factors.push_back(N);
  return factors;
}

bool isPrime(lli N) {
  if (N <= 1000000) return seive[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}

int main(){
   //freopen("out.txt","w",stdout);
   cal_primes(1000000);
   vector <int> div;
   map <int,int> mp;
   int n,m,i,j;
   bool flag;
   while(scanf("%d %d",&n,&m)==2){
       if((isPrime(m) && n<m ) || m==0) {  printf("%d does not divide %d!\n",m,n); continue;}
       if(m==1 || n>=m){ printf("%d divides %d!\n",m,n); continue; }
       flag=true;
       mp.clear();
       div=primeFactors((lli)m);
       for(i=0;i<div.size();i++) mp[div[i]]++;
       map <int,int> :: iterator k;
       for(k=mp.begin();k!=mp.end();k++){
            int t=k->first;
            int sum=0,power=1;
            while(floor(n/pow(t,power))>0){
                sum+=floor(n/pow(t,power));
                power++;
            }
            if(sum<k->second){
                flag=false; break;
            }
       }
       if(flag) printf("%d divides %d!\n",m,n);
       else     printf("%d does not divide %d!\n",m,n);
   }
   return 0;
}
