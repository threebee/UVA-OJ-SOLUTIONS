#include <cstdio>

int main(){
 int cd,n;
 while(scanf("%d %d",&cd,&n)!=EOF){
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    int max_sum=0,max_mask=0,sum=0,mask;

    for(mask=0; mask <(1<<n);mask++){
        sum=0;
        for(int i=0;i<n;i++)
            sum+=((1<<i) & mask)? a[i] : 0;
        if(sum>max_sum && sum<=cd)
            max_sum=sum,max_mask=mask;
    }
    for(int i=0;i<n;i++)
        if(max_mask & (1<<i))
          printf("%d ",a[i]);
    printf("sum:%d\n",max_sum);
 }
 return 0;
}
