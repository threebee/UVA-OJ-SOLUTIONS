#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main(){
    string a;
    while(cin>>a){
        for(int i=0;i<a.size();i++)
            a[i]-=7;
        printf("%s\n",a.c_str());
    }
    return 0;
}
