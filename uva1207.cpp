#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int table[1005][1005];

int main() {
  char A[1005],B[1005];
  int n,m;
  int i,j;
  while(scanf("%d %s %d %s",&n,A,&m,B)==4){
      memset(table, 0, sizeof table);
      for(i=1;i<=n;i++)  table[i][0]=i;
      for(j=1;j<=m;j++)  table[0][j]=j;

      for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
          table[i][j]=table[i-1][j-1]+(A[i-1]==B[j-1] ? 0:1);
          table[i][j]=min(table[i][j],table[i-1][j]+1);
          table[i][j]=min(table[i][j],table[i][j-1]+1);
      }
      printf("%d\n",table[n][m]);
  }
  return 0;
}

