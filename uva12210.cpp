#include <cstdio>
#include <algorithm>

int main(){
 int b,s,cas=1;
 while(scanf("%d %d",&b,&s)){
    if(b==0 && s==0) break;
    int bs[b],ss[s];
    for(int i=0;i<b;i++) scanf("%d",&bs[i]);
    for(int i=0;i<s;i++) scanf("%d",&ss[i]);
    std::sort(bs,bs+b);
    printf("Case %d: ",cas++);
    if(b<=s)
        printf("0");
    else {
        printf("%d %d",b-s,bs[0]);
    }
    printf("\n");
 }
 return 0;
}
