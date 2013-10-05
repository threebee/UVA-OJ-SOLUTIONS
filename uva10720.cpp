#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){
  return a>b;
}

int main(){
 int n,i,j;
 bool flag;
 while(scanf("%d",&n)){
    if(n==0) break;
    int a[n+1],temp[n+1];
    long long int total=0;
    flag=false;
    for(i=1;i<=n;i++) scanf("%d",&a[i]),total+=a[i];
    if(total%2 || total>n*(n-1) || total<0){  printf("Not possible\n"); continue; }
    sort(a+1,a+1+n,cmp);
    for(i=1;i<=n;i++) temp[i]=a[i];
    for(i=2;i<=n;i++) temp[i]+=temp[i-1];
    for(i=1;i<=n;i++){
       total=0;
       for(j=i+1;j<=n;j++)
        total+=min(i,a[j]);
       if(temp[i]>((i*(i-1))+total)) flag=true;
    }
    if(flag) printf("Not possible\n");
    else     printf("Possible\n");
 }

 return 0;
}
