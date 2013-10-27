#include <cstdio>

int countbits(int m){
    int counter=0;
    for(int i=0;i<32;i++)
        if(m & (1<<i)) counter++;
    return counter;
}

int main(){
    int t,b1,b2,m;
    char convert[100];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        b1=countbits(m);
        sprintf(convert,"%d",m);
        sscanf(convert,"%x",&m);
        b2=countbits(m);
        printf("%d %d\n",b1,b2);
    }
    return 0;
}
