#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int t,n,high,low,tmp1,tmp2,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%d",&tmp1);
        high=low=0;
        while(n-->1){
            scanf("%d",&tmp2);
            if(tmp2>tmp1)      high++;
            else if(tmp2<tmp1) low++;
            else { }
            tmp1=tmp2;
        }
        printf("Case %d: %d %d\n",++cas,high,low);
    }
    return 0;
}
