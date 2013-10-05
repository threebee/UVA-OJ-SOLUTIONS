#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<cstdio>
#include<cstring>
#include<cmath>
#define FF(i, a, b) for(int i=a; i<b; i++)
#define FD(i, a, b) for(int i=a; i>b; i--)
#define REP(i, n) for(int i=0; i<n; i++)
#define CLR(a, b) memset(a, b, sizeof(a))
#define LL long long

using namespace std;

const int maxn = 111;
char ch[maxn][maxn];
int n, m, g[maxn][maxn];

int main()
{
    int kase = 1;
    while(cin>>n>>m)
    {
        if(n + m == 0) break;
        if(kase > 1) puts("");
        CLR(g, 0);
        FF(i, 1, n+1)
        {
            cin>>ch[i]+1;
            FF(j, 1, m+1) if(ch[i][j] == '*')
            {
                g[i-1][j-1]++, g[i-1][j]++, g[i-1][j+1]++;
                g[i][j-1]++, g[i][j+1]++;
                g[i+1][j]++, g[i+1][j-1]++, g[i+1][j+1]++;
            }
        }
        printf("Field #%d:\n", kase++);
        FF(i, 1, n+1)
        {
            FF(j, 1, m+1)
            {
                if(ch[i][j] == '*') cout<<'*';
                else cout<<g[i][j];
            }
            puts("");
        }
    }
    return 0;
}
