#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

int main(){
 int t,i,j,k;
 long long int mini,maxi;
 char input[100],*pch;
 vector <int> v;
 vector <long long int> ans;
 vector <char> op;
 scanf("%d",&t);
 while(t--){
    mini=0; maxi=0;
    v.clear(); ans.clear(); op.clear();
    scanf("%s",input);
    for(i=0;i<strlen(input);i++){
        if(input[i]=='+' || input[i]=='*')
            op.push_back(input[i]);
    }
    for(pch=strtok(input,"+*");pch;pch=strtok(NULL,"+*")){
        v.push_back(atoi(pch));
    }
    //add first for maximum
    ans.push_back(v[0]);
    k=1;
    for(i=0;i<op.size();i++){
        if(op[i]=='+'){
            ans[ans.size()-1]+=v[k++];
            continue;
        }
        ans.push_back(v[k++]);
    }
    maxi=1;
    for(i=0;i<ans.size();i++) maxi*=ans[i];
    ans.clear();
    //multiply first for minimum
    ans.push_back(v[0]);
    k=1;
    for(i=0;i<op.size();i++){
        if(op[i]=='*'){
            ans[ans.size()-1]*=v[k++];
            continue;
        }
        ans.push_back(v[k++]);
    }
    mini=0;
    for(i=0;i<ans.size();i++) mini+=ans[i];
    ans.clear();
    printf("The maximum and minimum are %lld and %lld.\n",maxi,mini);
 }
 return 0;
}
