#include <cstdio>

int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        if(n>=m && (n+m)%2==0)   printf("%d %d\n",(n+m)/2,(n-m)/2);
        else                     printf("impossible\n");
    }
    return 0;
}

