#include <cstdio>

int main(){
 int n;
 while(scanf("%d",&n)){
    if(n==0) break;
    int a[n];
    bool flag=true;
    bool space=false;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=0) flag=false;
    }
    if(flag) printf("0");
    else{
        for(int i=0;i<n;i++){
            if(a[i]!=0){
                if(space) printf(" ");
                space = true;
                printf("%d",a[i]);
            }
        }
    }
    printf("\n");
 }
 return 0;
}
