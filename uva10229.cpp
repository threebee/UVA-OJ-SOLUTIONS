#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
typedef long long  ll;
ll MOD;
#define MAX_N 2

struct Matrix { ll mat[MAX_N][MAX_N]; };

Matrix matMul(Matrix a, Matrix b) {
  Matrix ans; int i, j, k;
  for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
      for (ans.mat[i][j] = k = 0; k < MAX_N; k++) {
        ans.mat[i][j] += (a.mat[i][k] % MOD) * (b.mat[k][j] % MOD);
        ans.mat[i][j] %= MOD;
      }
  return ans;
}

Matrix matPow(Matrix base, int p) {
  Matrix ans; int i, j;
  for (i = 0; i < MAX_N; i++)
    for (j = 0; j < MAX_N; j++)
      ans.mat[i][j] = (i == j);
  while (p) {
    if (p & 1)  ans = matMul(ans, base);                                // update ans
    base = matMul(base, base);
    p >>= 1;
  }
  return ans;
}

int main(){
    int n,m,i;
    while (scanf("%d %d", &n, &m) == 2) {
       Matrix ans;
       ans.mat[0][0] = 1;  ans.mat[0][1] = 1;
       ans.mat[1][0] = 1;  ans.mat[1][1] = 0;
       for (MOD = 1, i = 0; i < m; i++)
       MOD *= 2;
       ans = matPow(ans, n);                                       // O(log n)
       printf("%lld\n", ans.mat[0][1]);
  }
  return 0;
}
