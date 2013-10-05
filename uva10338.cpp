#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;
#define lli unsigned long long int

lli fac[]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,
           6227020800,87178291200,1307674368000,20922789888000,355687428096000,
           6402373705728000,121645100408832000,2432902008176640000};
int ct[26];

int main(){
   int t,i,cas=0;
   string s;
   lli ways;
   scanf("%d",&t);
   while(t--){
       cin>>s;
       memset(ct,0,sizeof ct);
       for(i=0;i<s.length();i++) ct[s[i]-'A']++;
       ways=fac[s.length()];
       for(i=0;i<26;i++){
        if(ct[i]) ways/=fac[ct[i]];
       }
       cout<<"Data set "<<++cas<<": "<<ways<<endl;
   }
   return 0;
}
