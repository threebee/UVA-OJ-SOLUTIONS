#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
char grid[150][150];
int R,C;

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 8; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main(){
   while(scanf("%d %d",&R,&C),(R || C)){
       scanf("\n");
       for(int i=0;i<R;i++) gets(grid[i]);
       int counts=0;
       for(int i=0;i<R;i++) for(int j=0;j<C;j++)
        if(grid[i][j]=='@') counts++,floodfill(i,j,'@','.');
       printf("%d\n",counts);
   }
   return 0;
}
