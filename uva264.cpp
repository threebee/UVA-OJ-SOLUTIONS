#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
 // freopen("out.txt","w",stdout);
  vector <int> v;
  int n=1;
  while(1){
    if((n*(n+1))/2 > 10000000) break;
    v.push_back((n*(n+1))/2);
    n++;
  }
  v.push_back(10004048);
  while(scanf("%d",&n)==1){
      int j=int(lower_bound(v.begin(),v.end(),n)-v.begin());
      int tmp=n;
      n-=v[j-1];
      int a=1,b=j+1;
      while(--n>0){
        a++,b--;
      }
      if(j%2==0) swap(a,b);
      printf("TERM %d IS %d/%d\n",tmp,a,b);
  }
  return 0;
}
