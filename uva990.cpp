#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

#define MAX_N 10000
#define MAX_W 100

typedef pair <int,int> ii;

vector <ii> v;
int memo[MAX_W][MAX_N],taken[MAX_W][MAX_N];
int w,n;

int value(int id,int remw){
   ii ans=v[id];
   if(id==n || remw==0) return 0;
   if(memo[id][remw]!=-1)  return memo[id][remw];
   if(3*w*ans.first>remw) return memo[id][remw]=value(id+1,remw);
   int a=value(id+1,remw);
   int b=ans.second+value(id+1,remw-3*w*ans.first);
   taken[id][remw]=(a<b);
   return memo[id][remw]=max(a,b);
}

int main(){
 int val,x,y;
 bool flag=false;
 while(scanf("%d %d",&val,&w)==2){
   memset(memo,-1,sizeof(memo));
   memset(taken,0,sizeof(taken));
   if(flag) printf("\n");
   flag=true;
   scanf("%d",&n);
   for(int i=0;i<n;i++){
    scanf("%d %d",&x,&y);
    v.push_back(ii(x,y));
 }
 printf("%d\n",value(0,val));
 int counts=0,i=0,j=val;
 vector <int> ans;
 while(i<n && j>=0){
    if(taken[i][j]){
        ans.push_back(i);
        counts++;
        j=j-3*w*v[i].first;
    }
    i++;
 }
 printf("%d\n",counts);
 for(int i=0;i<ans.size();i++)
    printf("%d %d\n",v[ans[i]].first,v[ans[i]].second);
 }
 return 0;
}

/*
#include <stdio.h>
#define max(a,b) (a>b)?a:b
int value[35],weight[35],dp[1005][35];
char taken[1005][35];
char mark[35];

int maxGold(int t,int n){
    if(!t||n<0) return 0;
    else if(dp[t][n]!=-1) return dp[t][n];
    else{
        int a = (t>=weight[n])?(value[n] + maxGold(t-weight[n],n-1)) : 0;
        int b = maxGold(t,n-1);
        taken[t][n]=(a>b);
        return dp[t][n]=max(a,b);
    }
}

int main(){
    int t,w,n,i,j,count,bl;
    bl=0;
    while(scanf("%d %d",&t,&w)==2){
        if(bl) putchar('\n');
        bl=1;
        scanf("%d",&n);
        i =0;
        while(i<n){
            scanf("%d %d",weight+i,value+i);
            weight[i]=3*w*weight[i];
            i++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<=t;j++){
                dp[j][i]=-1;
                taken[j][i]=0;
            }
            mark[i]=0;
        }
        printf("%d\n",maxGold(t,n-1));
        i=n-1;
        j=t;
        count=0;
        while(i>=0){
            if(taken[j][i]){
                mark[i]=1;
                count++;
                j = j-weight[i];
            }
            i--;
        }
        printf("%d\n",count);
        for(i = 0;i<n;i++)
            if(mark[i])
                printf("%d %d\n",weight[i]/3/w,value[i]);
    }
    return 0;
}

*/
