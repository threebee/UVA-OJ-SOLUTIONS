#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int swaps,t,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        swaps=0;
        int a[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);

        for(int i=0;i<n;i++)
            for(int j=0;j<n-i-1;j++)
               if(a[j]>a[j+1])
                  swap(a[j],a[j+1]),swaps++;
        printf("Optimal train swapping takes %d swaps.\n",swaps);

    }
    return 0;
}
