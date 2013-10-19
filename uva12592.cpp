#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main(){
    int n,m;
    map <string,string> mp;
    cin>>n;
    getchar();
    while(n--){
        string t1,t2;
        getline(cin,t1);
        getline(cin,t2);
        mp[t1]=t2;
    }
    cin>>m;
    getchar();
    while(m--){
        string t1;
        getline(cin,t1);
        cout<<mp[t1]<<endl;
    }
    return 0;
}
