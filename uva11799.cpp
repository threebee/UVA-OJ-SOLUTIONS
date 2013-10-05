#include <iostream>
#include <cstdio>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
 int t,n,i,input[10010],cnt=0;
 scanf("%d",&t);
 while(t--){
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",input+i);
    sort(input,input+n);
    printf("Case %d: %d\n",++cnt,input[n-1]);
 }
 return 0;
}
