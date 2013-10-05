#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int lds(vector <int> h,vector <int> w){
    vector <int> sum(h.size());
    for(int i=0;i<h.size();i++){
        sum[i]=w[i];
        for(int j=0;j<i;j++){
          if(h[i]<h[j])
            sum[i]=max(sum[i],sum[j]+w[i]);
        }
    }
    return *max_element(sum.begin(),sum.end());
}

int main(){
 int t,n,cas=1;
 scanf("%d",&t);
 while(t--){
    scanf("%d",&n);
    vector <int> a(n),b(n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++) scanf("%d",&b[i]);
    int ld=lds(a,b);
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int li=lds(a,b);
    if(li>=ld)  printf("Case %d. Increasing (%d). Decreasing (%d).\n",cas++,li,ld);
    else  printf("Case %d. Decreasing (%d). Increasing (%d).\n",cas++,ld,li);
 }
 return 0;
}
