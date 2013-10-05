#include <bitset>
#include <cmath>
#include <cstdio>
#include <map>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;
vi primes;


void sieve(ll upperbound) {
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
    for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
    primes.push_back((int)i);
  }
}

bool isPrime(ll N) {
  if (N <= _sieve_size) return bs[N];
  for (int i = 0; i < (int)primes.size(); i++)
    if (N % primes[i] == 0) return false;
  return true;
}

ll primeFactors(ll N) {
  ll largest;
  int counts=0;
  ll PF_idx = 0, PF = primes[PF_idx];
  while (N != 1 && (PF * PF <= N)) {
    if(N % PF == 0) counts++;
    while (N % PF == 0) { N /= PF; largest=PF; }
    PF = primes[++PF_idx];
  }
  if (N != 1)  largest=N,counts++;

  if(counts>=2) return largest;
  else          return -1;
}

int main(){
  sieve(10000000);
  long long n;
  while(cin>>n,n){
    n=abs(n);
    if(n==1){
        printf("-1\n");
        continue;
    }
    if(isPrime(n)) printf("-1\n");
    else           cout<<primeFactors(n)<<endl;
  }
  return 0;
}
