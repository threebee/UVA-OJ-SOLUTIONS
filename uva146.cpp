#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
 char a[55];
 while(cin>>a){
    if(!strcmp(a,"#")) break;
    if(next_permutation(a,a+strlen(a))) cout<<a<<endl;
    else cout<<"No Successor"<<endl;
 }
 return 0;
}
