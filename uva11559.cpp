#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
using namespace std;

struct hotel { int price,vac; }ho[20];

int main(){
  //freopen("out.txt","w",stdout);
  int n,b,h,w,i,j,min_cost,temp;
  while(scanf("%d %d %d %d",&n,&b,&h,&w)==4){
    for(i=0;i<h;i++){
        scanf("%d",&ho[i].price);
        ho[i].vac=0;
        for(j=0;j<w;j++){
            scanf("%d",&temp);
            ho[i].vac=max(ho[i].vac,temp);
        }
    }
    min_cost=INT_MAX;
    for(j=0;j<h;j++){
        if(ho[j].vac<n) continue;
        min_cost=min(min_cost,n*ho[j].price);
    }

    if(min_cost>b) printf("stay home\n");
    else       printf("%d\n",min_cost);
  }
  return 0;
}
