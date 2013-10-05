#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main(){
 int t,cnt,l,i,j,total,power;
 scanf("%d",&t);
 string ans;
 char input[12][128];
 getchar();
 while(t--){
    ans="";
    cnt=0;
    for(i=0;i<10;i++) scanf("%s",&input[i]);
    l=strlen(input[0]);
    for(i=1;i<l-1;i++){
        total=0,power=0;
        for(j=0;j<9;j++){
            if(input[j][i]=='\\') total+=(int)pow(2,power-1);
                power++;
        }
        ans+=(char)total;
    }
    cout<<ans<<endl;
 }
 return 0;
}
