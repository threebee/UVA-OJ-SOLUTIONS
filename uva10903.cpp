/*
  submission error
*/
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int,int> ii;

bool game(string str1,string str2){
    if(str1=="rock" && str2=="scissors")
        return true;
    else if(str1=="scissors" && str2=="paper")
        return true;
    else if(str1=="paper" && str2=="rock")
        return true;
    else return false;
}

int main(){
    int n,k,tmp1,tmp2;
    string str1,str2;
    bool blank=false;
    while(scanf("%d",&n),n){
        scanf("%d",&k);
        map <int,ii> mp;
        while(k--){
            cin>>tmp1>>str1>>tmp2>>str2;
            tmp1--,tmp2--;
            if(str1==str2) continue;
            else if(game(str1,str2)){
                mp[tmp1].first++;
                mp[tmp2].second++;
            }
            else{
                mp[tmp1].second++;
                mp[tmp2].first++;
            }
        }
        if(blank) printf("\n"); blank=true;
        for(int i=0;i<n;i++){
            if(mp[i].first==0 && mp[i].second==0) printf("-\n");
            else printf("%0.3f\n",(float)mp[i].first/(float)(mp[i].first+mp[i].second));
        }
    }
    return 0;
}
