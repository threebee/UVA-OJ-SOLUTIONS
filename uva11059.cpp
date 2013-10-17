#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long int lli;

int n,nums[20];
lli p,maxP=0;

lli sol(){
    maxP=0;
    for(int i=0 ;i<n; i++){
        p=1;
        for(int j=i ; j<n && p; j++){
            p*=nums[j];
            if(p>maxP) maxP=p;
        }
    }
    return maxP;
}

int main(){
    int cas=0;
    while(scanf("%d", &n)==1){
        for(int i=0; i<n; i++) scanf("%d",&nums[i]);
        printf("Case #%d: The maximum product is %lld.\n\n",++cas,sol());
    }
}
