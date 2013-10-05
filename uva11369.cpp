#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){ return a>b; }

int main(){
 int t;
 scanf("%d",&t);
 while(t--){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n,cmp);
    long long int total=0;
    for(int i=2;i<n;i+=3) total+=a[i];
    printf("%lld\n",total);
 }
 return 0;
}
