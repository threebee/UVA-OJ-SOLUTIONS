#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
 int t,n,sum,val;
 bool m[25001];
 scanf("%d",&t);
 while(t--){
    memset(m,0,sizeof(m));
    scanf("%d\n",&n);
    int a[n],j;
    sum=0;
    for(int i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
    m[0]=true;
    val=sum/2;
    for(int i=0;i<n;i++){
        for(j=val;j>0;j--){
            if(!m[j])
                m[j]=(a[i]<=j)?m[j-a[i]]:false;
        }
    }
    for(j=val;j>0;j--)
       if(m[j]) break;
    int ans=sum-2*j;
    //printf("%d %d\n",sum,j);
    ans=(ans>0)?ans:-ans;
    printf("%d\n",ans);
 }
 return 0;
}
