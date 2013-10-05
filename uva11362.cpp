#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

bool check(string x,string y){
    if(x.length()>y.length()) return false;
    for(int i=0;i<x.length();i++)
        if(x[i]!=y[i]) return false;
    return true;
}

int main(){
    int t,n,i;
    cin>>t;
    bool flag;
    string s[10010];
    while(t--){
      cin>>n;
      flag=false;
      for(i=0;i<n;i++) cin>>s[i];
      sort(s,s+n);
      for(i=1;i<n;i++){
        if(check(s[i-1],s[i])){
            flag=true;
            break;
        }
      }
      if(flag) cout<<"NO\n";
      else     cout<<"YES\n";
    }
    return 0;
}
