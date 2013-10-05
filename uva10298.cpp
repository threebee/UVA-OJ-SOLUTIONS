#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string T,P;
int counts;
int b[1000010];

void kmpPreprocess() {
  int i=0,j=-1;b[0]=-1;
  while(i<P.length()) {
    while (j>=0 && P[i]!=P[j]) j=b[j];
    i++; j++;
    b[i]=j;
  }
}

int kmpSearch(){
  int i=1,j=0;
    while(i<T.length()){
      while(j>=0 && T[i]!=P[j]) j=b[j];
      i++; j++;
      if(j==P.length()){
        return i-j;
        j=b[j];
      }
    }
}

int main(){
 int i;
 while(1){
    cin>>P;
    if(P==".") break;
    T=P+P;
    kmpPreprocess();
    cout<<P.length()/kmpSearch()<<endl;
 }
 return 0;
}
