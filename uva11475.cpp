#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int b[1000100];
string P,T;

void kmpPreprocess() {
  int i=0,j=-1;b[0]=-1;
    while(i<P.length()){
      while(j>=0 && P[i]!=P[j]) j=b[j];
      i++; j++;
      b[i]=j;
    }
}

int kmpSearch(){
  int i=0,j=0;
  while (i<T.length()){
    while (j >= 0 && T[i] != P[j]) j = b[j];
    i++; j++;
    if (j==P.length()){
        return j;
      j=b[j];
    }
  }
  return j;
}

int main(){
 char  a[1000100];
 while(scanf("%s",a)==1){
   P=T=a;
   reverse(P.begin(),P.end());
   memset(b,0,sizeof(b));
   kmpPreprocess();
   int v=kmpSearch();
   cout<<T;
   for(int i=v;i<P.length();i++) cout<<P[i];
   cout<<endl;
 }
 return 0;
}
