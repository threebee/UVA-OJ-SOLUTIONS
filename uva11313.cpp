#include <cstdio>

int main() {
    int x,y,i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++) {
        scanf("%d %d",&x,&y);
        if((x-1)%(y-1)!=0){
            printf("cannot do this\n");
        }else{
            printf("%d\n",(x-1)/(y-1));
        }
    }
    return 0;
}
