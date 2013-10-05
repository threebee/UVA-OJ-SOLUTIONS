#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t,ans1[50010],ans2[50010];
    scanf("%d",&t);
    while(t--){
        int s,a,f;
        scanf("%d %d %d",&s,&a,&f);
        for(int i=0;i<f;i++)
            scanf("%d %d",&ans1[i],&ans2[i]);
        sort(ans1,ans1+f);
        sort(ans2,ans2+f);
         if(f%2) printf("(Street: %d, Avenue: %d)\n",ans1[f/2],ans2[f/2]);
         else    printf("(Street: %d, Avenue: %d)\n",ans1[(f-1)/2],ans2[(f-1)/2]);
    }
    return 0;
}
