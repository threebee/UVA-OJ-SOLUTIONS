#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

string T,P;
int counts;

void process(){
    size_t found=T.find(P);
    if(found!=string::npos) counts++;
    while(found!=string::npos){
        found=T.find(P,found+P.length());
        if(found!=string::npos) counts++;
    }
}

int main(){
 int t,i;
 scanf("%d",&t);
 bool space=false;
 while(t--){
    cin>>T;
    for(i=1;i<=T.length();i++){
      if(T.length()%i==0){
        P=T.substr(0,i);
        counts=0;
        process();
        if(T.length()/i==counts) break;
      }
    }
    cout<<i<<endl;
    if(t) cout<<endl;
 }
 return 0;
}
