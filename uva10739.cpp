#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int table[1001][1001];

int main() {
  int t,counts=0,n,m,i,j;
  scanf("%d",&t);
  string A,B;
  while(t--){
    cin>>A; B=A;
    reverse(B.begin(),B.end());
    n=m=A.length();
    memset(table,0,sizeof table);
    for(i=1;i<=n;i++) table[i][0]=i,table[0][i]=i; ;

    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++){
      // match = 2 points, mismatch = -1 point
        table[i][j]=table[i-1][j-1]+(A[i-1]==B[j-1] ? 0 : 1); // cost for match or mismatches
      // insert/delete = -1 point
      table[i][j] = min(table[i][j], table[i-1][j]+1); // delete
      table[i][j] = min(table[i][j], table[i][j-1]+1); // insert
    }
    printf("Case %d: %d\n",++counts,table[n][m]/2);
  }
  return 0;
}
