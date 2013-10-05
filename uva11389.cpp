#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){ return a>b; };

int main(){
 int n,d,r;
 while(scanf("%d %d %d",&n,&d,&r) && n && d && r){
    int a[n],b[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    sort(a,a+n);
    sort(b,b+n,cmp);
    int total_overtime=0;
    for(int i=0;i<n;i++){
        total_overtime+=(a[i]+b[i]>d)?(a[i]+b[i]-d):0;
    }
    printf("%d\n",total_overtime*r);
 }
 return 0;
}
