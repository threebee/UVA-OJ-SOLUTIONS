#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int cas;
    while(scanf("%d",&cas) && cas!=-1){
     string tmp1,tmp2;
     cin>>tmp1>>tmp2;
     set <char> chs(tmp1.begin(),tmp1.end());
     string t(chs.begin(),chs.end());
     int j,counts=0;
     for(j=0;j<tmp2.size();j++){
        size_t pos=t.find(tmp2[j]);
        if(pos!=string::npos){
            t.erase(t.begin()+pos);
        }
        else counts++;

        if(t=="") break;
     }
     printf("Round %d\n",cas);
     if(counts<7 && t=="") printf("You win.\n");
     else if(counts<7 && t!="") printf("You chickened out.\n");
     else  printf("You lose.\n");
    }
    return 0;
}
