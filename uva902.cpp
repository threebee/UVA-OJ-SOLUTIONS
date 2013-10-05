#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int main(){
  char val[15];
  string a;
  int n,i,j,k;
  while(cin>>n>>a){
    map <string,int> mp;
    for(int i=0;i<a.length()-n+1;i++){
        k=0;
        for(j=i;j<i+n;j++) val[k++]=a[j];
        val[k]='\0';
        if(!mp.count(val)) mp[val]=1;
        else mp[val]++;
    }

    map <string,int> :: iterator it;
    int maxi=0;
    string maxi1;
    for(it=mp.begin();it!=mp.end();++it){
         if(maxi<(it->second)){
            maxi=it->second;
            maxi1=it->first;
         }
    }
    cout<<maxi1<<endl;
  }
 return 0;
}
