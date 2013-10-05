#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

int main(){
   vector <int> v;
   int n,i,tmp,tmp1;
   while(scanf("%d",&n),n){
      v.clear();
      tmp=n;
      if(n<0){
        v.push_back(-1);
        n*=(-1);
      }
      tmp1=sqrt(n);
      for(i=2;i<=tmp1;i++)
          if(n%i==0){
            while(n%i==0)  v.push_back(i),n/=i;
          }

      if(n!=1) v.push_back(n);
      printf("%d = %d",tmp,v[0]);
      for(i=1;i<v.size();i++) printf(" x %d",v[i]);
      printf("\n");
   }
   return 0;
}
