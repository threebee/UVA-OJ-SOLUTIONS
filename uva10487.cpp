#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(){
 int n,q,arr[1010],i,j,val,mini,mini_id,tmp,cas=0;
 while(scanf("%d",&n),n){
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    scanf("%d",&q);
    printf("Case %d:\n",++cas);
    while(q--){
        scanf("%d",&val);
        if(n==1){
           printf("Closest sum to %d is %d.\n",val,arr[0]);
           continue;
        }
        mini=INT_MAX;
        mini_id=0;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++){
                tmp=arr[i]+arr[j];
                if(mini > abs(val-tmp)) mini=abs(val-tmp),mini_id=tmp;
            }
        printf("Closest sum to %d is %d.\n",val,mini_id);
    }
 }
 return 0;
}
