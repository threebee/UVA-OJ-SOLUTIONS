#include <cstdio>

int main(){
    int t,m,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        printf("%d\n",((int)(n/3))*((int)(m/3)));
    }
    return 0;
}
