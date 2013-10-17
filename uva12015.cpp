#include <iostream>
#include <cstdio>
using namespace std;

int main (){
    int t,cas=0;
    char urls[15][110];
    int val[15];
    scanf("%d",&t);
    while(t--){
        int maxi=-1;
        for(int i=0; i<10; i++){
            scanf("%s %d",urls[i],&val[i]);
            maxi=max(maxi,val[i]);
        }
        printf ("Case #%d:\n",++cas);

        for(int i=0; i<10; i++)
           if(maxi==val[i])
             printf("%s\n",urls[i]);
    }
    return 0;
}
