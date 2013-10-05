#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main(){
    int n,m,i;
    map <string, string> mp;
    cin>>n>>m;
    for(i=0; i<n; i++){
        string first, second;
        cin>>first>>second;
        mp[first] = second;
    }
    for(i=0; i<m; i++){
        string str;
        cin>>str;
        if(mp.count(str)){
            cout<<mp[str]<<endl;
            continue;
        }
        int len = str.length();
        if( str[len-1]=='y' && !(str[len-2]=='a' || str[len-2]=='e' || str[len-2]=='i' || str[len-2]=='o' || str[len-2]=='u') ){
             str.erase(len-1);
             str += "ies";
        }
        else if( str[len-1]=='o' ||  str[len-1]=='s' ||  str[len-1]=='x' || (str[len-1]=='h' && (str[len-2]=='c' || str[len-2]=='s') ) ){
            str += "es";
        }
        else{
            str += "s";
             }
        cout<<str<<endl;
    }
    return 0;
}
