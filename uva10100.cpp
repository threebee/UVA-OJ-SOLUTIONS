#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
using namespace std;

string a[1100],b[1100];
int memo[1100][1100];

int lcs(int i,int j){
    if(i<0 || j<0) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    if(a[i]==b[j]) return memo[i][j]=lcs(i-1,j-1)+1;
    else           return memo[i][j]=max(lcs(i-1,j),lcs(i,j-1));
}

int main(){
 int n,m,i,j,k,counts=0;
 char temp1[1100],temp2[1100],*pch;
 while(gets(temp1)){
    gets(temp2);
    cout.width(2);
    cout <<++counts<<". ";
    n=m=0;
    if(!strlen(temp1) || !strlen(temp2)){
        cout<<"Blank!\n";
        continue;
    }
    memset(memo,-1,sizeof memo);
    for(pch=strtok(temp1," -,.");pch;pch=strtok(NULL," ,.\\/;'[]`!@#$%^&*()-=_+~<>?|:\"{}|"))   a[n++]=pch;
    for(pch=strtok(temp2," -,.");pch;pch=strtok(NULL," ,.\\/;'[]`!@#$%^&*()-=_+~<>?|:\"{}|"))   b[m++]=pch;
    cout<<"Length of longest match: "<<lcs(n-1,m-1)<<endl;
 }
 return 0;
}
