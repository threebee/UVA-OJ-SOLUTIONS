#include <cstdio>

int main(){
 int t;
 scanf("%d",&t);
 while(t--){
    int n;
    scanf("%d",&n);
    int a[n+1],i;
    float sum=0.0;
    for(i=0;i<n;i++) scanf("%d",&a[i]),sum+=a[i];
    sum=sum/(float)n;
    int k=0;
    for(i=0;i<n;i++)
        if(a[i]>sum) k++;
    float percent=((float)k*100)/(float)n;
    printf("%0.3f%%\n",percent);
 }
 return 0;
}
