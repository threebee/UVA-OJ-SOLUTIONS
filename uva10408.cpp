#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

struct point {int x,y;};

int gcd(int a,int b){ return b? gcd(b,a%b):a; }

bool cmp(point a,point b){
    return (double)(a.x/(double)a.y)<(double)(b.x/(double)b.y);
}

int main(){
   vector <point> vp;
   point temp;
   int n,k,i,j;
   while(scanf("%d %d",&n,&k)==2){
    vp.clear();
    for(i=1;i<=n;i++) for(j=i;j<=n;j++){
       // cout<<i<<" "<<j<<" "<<gcd(i,j)<<endl;
        if(gcd(i,j)==1){
           temp.x=i,temp.y=j;
           vp.push_back(temp);
        }
    }
    sort(vp.begin(),vp.end(),cmp);
   // for(i=0;i<vp.size();i++) cout<<vp[i].x<<"/"<<vp[i].y<<endl;
    temp=vp[k-1];
    printf("%d/%d\n",temp.x,temp.y);
   }
   return 0;
}
