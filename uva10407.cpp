#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a,int b) { return b ? gcd(b,a%b) : a; }

int main(){
    int arr[1010],counts,i,ans,tmp;
    while(scanf("%d",&arr[0]),arr[0]){
        counts=1;
        while(scanf("%d",&arr[counts]),arr[counts]) ++counts;
        tmp=arr[0];
        for(i=0;i<counts;i++) arr[i]-=tmp;
        ans=arr[1];
        for(i=2;i<counts;i++) ans=gcd(ans,arr[i]);
        if(ans<0) ans*=(-1);
        printf("%d\n",ans);
    }
    return 0;
}
