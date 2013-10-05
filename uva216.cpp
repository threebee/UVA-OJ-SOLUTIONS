#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

struct point { float x,y; };

float sq(float x) { return x*x; };

int main(){
 point p[8];
 int n,i,permute[8],temp[8],cnt=0;
 float mini,dist;
 while(scanf("%d",&n) && n){
     for(i=0;i<n;i++){
        permute[i]=i;
        scanf("%f %f",&p[i].x,&p[i].y);
     }
     mini=INT_MAX;
     do{
        dist=0.0;
        for(i=0;i<n-1;i++){
            dist+=(sqrt(sq(p[permute[i]].x-p[permute[i+1]].x)+sq(p[permute[i]].y-p[permute[i+1]].y)));
        }
        if(mini>dist){
           for(i=0;i<n;i++)
            temp[i]=permute[i];
           mini=dist;
        }
     }while(next_permutation(permute,permute+n));
     printf("**********************************************************\n");
     printf("Network #%d\n",++cnt);
     float total=0.0,tmp;
     for(i=0;i<n-1;i++){
        tmp=sqrt(sq(p[temp[i]].x-p[temp[i+1]].x)+sq(p[temp[i]].y-p[temp[i+1]].y))+16;
        total+=tmp;
        printf("Cable requirement to connect (%.0f,%.0f) to (%.0f,%.0f) is %0.2f feet.\n",p[temp[i]].x,p[temp[i]].y,p[temp[i+1]].x,p[temp[i+1]].y,tmp);
     }
     printf("Number of feet of cable required is %0.2f.\n",total);
 }
 return 0;
}
