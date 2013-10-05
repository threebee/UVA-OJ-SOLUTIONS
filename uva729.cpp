#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main(){
  int N,H,t,i;
  bool flag=false;
  string str;
  scanf("%d",&t);
  while(t--){
    str="";
    if(flag) printf("\n");
    flag=true;
    scanf("%d %d",&N,&H);
    for(i=0;i<N-H;i++) str+='0';
    for(i=0;i<H;i++) str+='1';
    do{
      printf("%s\n",str.c_str());
    }while(next_permutation(str.begin(),str.end()));

  }
  return 0;
}
