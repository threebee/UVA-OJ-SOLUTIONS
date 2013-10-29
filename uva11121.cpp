#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n,r,cas=0,b=-2,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        printf("Case #%d: ",++cas);
        string str="";
        if(!n) str="0";
        while(n != 0){
          r=n%b;
          n/=b;
          if(r<0) r+=2,n+=1;
          str = (char)(r+'0') + str;
        }
        printf("%s\n",str.c_str());
    }
    return 0;
}
