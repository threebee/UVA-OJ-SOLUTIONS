#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int k,di,dj,ti,tj;
    while(scanf("%d",&k),k){
        scanf("%d %d",&di,&dj);
        while(k--){
            scanf("%d %d",&ti,&tj);
            if(ti==di || tj==dj)        printf("divisa\n");
            else if((ti>di) && (tj>dj)) printf("NE\n");
            else if((ti<di) && (tj<dj)) printf("SO\n");
            else if((ti<di) && (tj>dj)) printf("NO\n");
            else                        printf("SE\n");
        }
    }
    return 0;
}
