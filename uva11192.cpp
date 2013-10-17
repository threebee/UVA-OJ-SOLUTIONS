#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n;
    string str;
    while(scanf("%d",&n),n){
        cin>>str;
        string fin="";
        int k=str.length()/n;
        for(int i=0;i<str.length();i+=k){
            string tmp=str.substr(i,k);
            reverse(tmp.begin(),tmp.end());
            fin=fin+tmp;
        }
        cout<<fin;
        printf("\n");
    }
    return 0;
}
