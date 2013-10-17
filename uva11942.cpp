#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int t,a[10];
    scanf("%d",&t);
    printf("Lumberjacks:\n");
    while(t--){
        int inc=1,dec=1;
        scanf("%d",&a[0]);
        for(int i=1;i<10;i++){
            scanf("%d",&a[i]);
            if(a[i]>a[i-1]) inc++;
            else if(a[i]<a[i-1]) dec++;
            else inc++,dec++;
        }
        if(inc==10 || dec==10)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}
