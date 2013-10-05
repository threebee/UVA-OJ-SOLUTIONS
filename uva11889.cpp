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


int main(){
   //freopen("out.txt","w",stdout);
   cal_primes(1000000);
   vector <int> div1,div2;
   map <int,int> mp,mp2;
   int a,b,c,i,j,t;
   bool flag;
   scanf("%d",&t);
   while(t--){
       scanf("%d %d",&a,&c);
       div1=primeFactors(c);
       div2=primeFactors(a);
       mp.clear();
       flag=true;
       for(i=0;i<div1.size();i++){ mp[div1[i]]++; }
       for(i=0;i<div2.size();i++){
            if(mp[div2[i]]) mp[div2[i]]--;
            else flag=false;
       }
       if(!flag){
            printf("NO SOLUTION\n");
            continue;
       }
       mp.clear();
       mp2.clear();
       map <int,int> :: iterator k;
       for(i=0;i<div1.size();i++){ mp[div1[i]]++; }
       for(i=0;i<div2.size();i++){ mp2[div2[i]]++; }

       for(k=mp.begin();k!=mp.end();k++){
            if(mp[k->first]==mp2[k->first]) mp[k->first]=0;
       }
       int product=1;
       for(k=mp.begin();k!=mp.end();k++){
            if(mp[k->first]){
                while(mp[k->first]){
                    product*=k->first;
                    mp[k->first]--;
                }
            }
       }
       printf("%d\n",product);
   }
   return 0;
}
