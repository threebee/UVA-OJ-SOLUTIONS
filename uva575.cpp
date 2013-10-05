#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    string a;
    while(cin>>a){
        if(a.compare("0")==0) break;
        long long int total=0;
        reverse(a.begin(),a.end());
        for(long long int i=0;i<a.length();i++)
          total+=(a[i]-48)*((1<<(i+1))-1);
        cout<<total<<endl;
    }
    return 0;
}
