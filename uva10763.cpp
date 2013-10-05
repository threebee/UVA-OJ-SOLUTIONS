#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int v1[550000],v2[550000];

int main(){
    int n,i;
    bool flag;
    while(scanf("%d",&n),n){
            flag=false;
            for(i=0;i<n;i++)
                scanf("%d %d",&v1[i],&v2[i]);
            sort(v1,v1+n);
            sort(v2,v2+n);
            for(i=0;i<n;i++)
                if(v1[i]!=v2[i]){
                    flag=true; break;
                }

            if(flag) printf("NO\n");
            else     printf("YES\n");

    }
    return 0;
}
