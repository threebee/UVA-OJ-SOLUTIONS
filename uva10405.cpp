#include <cstdio>
#include <cstring>
using namespace std;
#define max(a,b) a>b?a:b

char A[1100],B[1100];
int memo[1100][1100];

int lcs(int i,int j){
    if(!A[i] || !B[j]) return memo[i][j]=0;
    if(memo[i][j]!=-1) return memo[i][j];
    if(A[i]==B[j]) return memo[i][j]=lcs(i+1,j+1)+1;
    else           return memo[i][j]=max(lcs(i+1,j),lcs(i,j+1));
}

int main(){
  while(gets(A) && gets(B)){
    memset(memo,-1,sizeof memo);
    printf("%d\n",lcs(0,0));
  }
  return 0;
}

