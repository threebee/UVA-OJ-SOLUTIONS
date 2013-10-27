#include <cstdio>

int main(){
    int t,x,y,diff,ct,start;
    bool flag;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&x,&y);
        diff=y-x;
        ct=0; start=1;
        flag=false;

        while(diff > 0){
            diff-=start;
            ct++;
            if(flag) start++;
            flag=!flag;
        }

        printf("%d\n",ct);
    }
    return 0;
}
