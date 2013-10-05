#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

int dist[21][21],x,memo[11][1<<11];

struct point { int x,y; };
int mfab(int x) {  return x>0?x:-x;  }

int tsp(int pos,int mask){
    if(mask == ((1<<x)-1)) return dist[pos][0];
    if(memo[pos][mask]!=-1) return memo[pos][mask];
    int ans=INT_MAX,nxt;
    for(nxt=0;nxt<x;nxt++){
       if( nxt!=pos && !(mask & (1<<nxt))){
          ans=min(ans,dist[pos][nxt] + tsp(nxt,mask|(1<<nxt)));
       }
    }
    return memo[pos][mask]=ans;
}

int main(){
 int i,j,t,n,m;
 point p[11];
 scanf("%d",&t);
 while(t--){
    scanf("%d %d",&n,&m);
    scanf("%d %d",&p[0].x,&p[0].y);
    scanf("%d",&x); x+=1;
    for(i=1;i<x;i++)
        scanf("%d %d",&p[i].x,&p[i].y);
    memset(dist,0,sizeof dist);
    memset(memo,-1,sizeof memo);
    for(i=0;i<x;i++) for(j=0;j<x;j++){
        dist[i][j]=mfab(p[i].x - p[j].x)+mfab(p[i].y - p[j].y);
    }
    printf("The shortest path has length %d\n",tsp(0,1));
 }
 return 0;
}
