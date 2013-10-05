#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

char temp[100];
vector <string> input;
int i,j,k,cnt;
bool flag;

bool check(string x,string y){
    if(x.length()>y.length()) return false;
    for(int i=0;i<x.length();i++)
        if(x[i]!=y[i]) return false;
    return true;
}

int main(){
 cnt=0;
 while(scanf("%s",temp)==1){
    flag=false;
    input.clear();
    input.push_back(temp);
    while(1){
       cin>>temp;
       if(!strcmp(temp,"9")) break;
       input.push_back(temp);
    }
    sort(input.begin(),input.end());
    for(int i=1;i<(int)input.size();i++){
        if(check(input[i-1],input[i])){
            flag=true;
            break;
        }
    }
    if(!flag) printf("Set %d is immediately decodable\n",++cnt);
    else     printf("Set %d is not immediately decodable\n",++cnt);
 }
 return 0;
}
