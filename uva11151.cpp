#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int b[1100][1100];
char T[1100];

int cal(int i,int j){
    if(i>j) return b[i][j]=0;
    if(i==j) return b[i][j]=1;
    if(b[i][j]!=-1) return b[i][j];

    if(T[i]==T[j]) return b[i][j]=2+cal(i+1,j-1);
    else           return b[i][j]=max(cal(i+1,j),cal(i,j-1));
}

int main(){
 int t;
 cin>>t;
 getchar();
 while(t--){
   gets(T);
   memset(b,-1,sizeof(b));
   cout<<cal(0,strlen(T)-1)<<endl;
 }
 return 0;
}


