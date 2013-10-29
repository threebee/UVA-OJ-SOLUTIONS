#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;
typedef long long int lli;

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m)==2){
        if(n<2 || m<2 || m>n){
            printf("Boring!\n");
            continue;
        }
        vector <int> v;
        bool flag=true;
        while(n>1){
            if(n%m){
               flag=false;
               break;
            }
            else {
               v.push_back(n);
               n/=m;
            }
        }
        if(flag){
            printf("%d",v[0]);
            for(int i=1;i<(int)v.size();i++)
                printf(" %d",v[i]);
            printf(" 1\n");
        }
        else{
            printf("Boring!\n");
        }
    }
    return 0;
}
