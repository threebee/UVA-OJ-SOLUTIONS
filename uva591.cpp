#include <cstdio>

int main(){
    int n,counts=0;
    while(scanf("%d",&n)){
        if(n==0) break;
        int a[n],total=0;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]),total+=a[i];
        int mean=total/n;
        total=0;
        for(int i=0;i<n;i++)
            if(a[i]>mean)
               total+=(a[i]-mean);
        printf("Set #%d\n",++counts);
        printf("The minimum number of moves is %d.\n\n",total);
    }

  return 0;
}
