#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a,int b){ return b ? gcd(b,a%b) : a; }
int max(int a,int b){ return a>b ? a : b; }

int main(){
  int t,i,j,ans;
  char input[10000],*pch;
  vector <int> v;
  scanf("%d",&t);
  getchar();
  while(t--){
    gets(input);
    v.clear();
    ans=0;
    for(pch=strtok(input," ");pch;pch=strtok(NULL," ")){
        v.push_back(atoi(pch));
    }
    for(i=0;i<v.size();i++)
        for(j=i+1;j<v.size();j++)
         ans=max(ans,gcd(v[i],v[j]));
    printf("%d\n",ans);
  }
  return 0;
}
