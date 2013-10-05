#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int b[100010];
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
    int t,k,w,j;
    cin>>t;
    while(t--){
        cin>>k>>w;
        T="";
        cin>>P;
        T=P;
        w--;
        while(w--){
            cin>>P;
            kmpPreprocess();
            j=kmpSearch();
            T+=P.substr(j);
        }
        cout<<T.size()<<endl;
    }
    return 0;
}
