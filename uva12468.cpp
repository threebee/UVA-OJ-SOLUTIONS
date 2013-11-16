#include <cstdio>
#include <iostream>
using namespace std;

int func(int a,int b){
    int k=max(a,b)-min(a,b);
    int j=100-max(a,b)+min(a,b);
    return min(k,j);
}

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)){
        if(a==-1 && b==-1) break;
        printf("%d\n",func(a,b));
    }
    return 0;
}
