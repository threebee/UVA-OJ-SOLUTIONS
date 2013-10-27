#include <cstdio>

int main(){
    char buffer[1000];
    int n,hh,mm,ss,sp=0,nsp=0,dist=0,time=0,now=0;

    while(gets(buffer)){
        n=sscanf(buffer,"%d:%d:%d %d", &hh, &mm, &ss, &nsp);
        now=hh*3600 + mm*60 + ss;
        dist+=(now-time)*sp;
        time=now;

        if(n==3)
            printf("%02d:%02d:%02d %.2lf km\n",hh,mm,ss,dist/(double)3600);
        if(n==4)
            sp=nsp;
    }
    return 0;
}
