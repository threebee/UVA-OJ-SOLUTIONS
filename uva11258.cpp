#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <climits>
using namespace std;

typedef long long int lli;

string str;
lli dp[210];
int n;

lli cal(int k){
    if(k==n) return 0;
    if(dp[k]!=-1) return dp[k];
    lli ret=0,sum=0;
    if(str[k]=='0')  ret=cal(k+1);
    else{
        int i;
        for(i=1;i<=10 && i+k<=n;i++){
            sum=sum*10+(str[k+i-1]-'0');
            if(sum<=INT_MAX) ret=max(ret,sum+cal(k+i));
        }
    }
    return dp[k]=ret;
}

int main(){
 int t;
 scanf("%d",&t);
 while(t--){
  cin>>str;
  n=str.length();
  memset(dp,-1,sizeof dp);
  cout<<cal(0)<<endl;
 }
 return 0;
}
