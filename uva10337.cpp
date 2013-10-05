#include <iostream>
#include <cstdio>
using namespace std;
#define INF 100000000
int memo[10][1010],mat[10][1010],n;

int ans(int i,int j){
    if(j==n && i==0) return 0;
    else if(j==n || i<0 || i>9) return INF;
    else if(memo[i][j]!=-1) return memo[i][j];
    else if(i==0){
         if(j==n-1) return memo[i][j] = min(min(60-mat[i][j]+ans(i+1,j+1),20-mat[i][j]+ans(i-1,j+1)),30-mat[i][j]+ans(i,j+1));
         else return memo[i][j] =  min(60-mat[i][j]+ans(i+1,j+1),20-mat[i][j]+ans(i-1,j+1));
    }
    else{
        return memo[i][j]=min(min(60-mat[i][j]+ans(i+1,j+1),20-mat[i][j]+ans(i-1,j+1)),30-mat[i][j]+ans(i,j+1));
    }
}

int main(){
 int t,i,j;
 scanf("%d",&t);
 while(t--){
    scanf("%d",&n);
    n=n/100;
    for(i=9;i>=0;i--)
        for(j=0;j<n;j++){
           scanf("%d",&mat[i][j]);
           memo[i][j]=-1;
        }
    printf("%d\n\n",ans(0,0));
 }
 return 0;
}
