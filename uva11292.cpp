#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

//bool cmp(int x,int y){ return x>y; };

int main(){
    int n,m;
   // freopen("out.txt","w",stdout);
    while(scanf("%d %d",&n,&m)){
        if(n==0 && m==0) break;
        int a[n],b[m],i;
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        for(i=0;i<m;i++) scanf("%d",&b[i]);
        if(n>m){
            printf("Loowater is doomed!\n");
            continue;
        }
        sort(a,a+n);
        sort(b,b+m);
        int total=0;
        bool flag=false;
        int k=0,p=0;
        while(k<n && p<m){
            if(a[k]>b[p]){p++;}
            else { total+=b[p]; k++,p++; }
        }
        if(k<n) printf("Loowater is doomed!\n");
        else     printf("%d\n",total);
    }
 return 0;
}
