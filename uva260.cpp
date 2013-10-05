#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dr[] = {-1,-1,0,0,1,1};
int dc[] = {-1,0,-1,1,0,1};
char grid[250][250],ans;
int R,C;
bool visited[250][250];

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    if ( c == R-1 && grid[r][c] == 'w' ) { ans = 'W'; return 0; }
    if ( r == R-1 && grid[r][c] == 'b' ) { ans = 'B'; return 0; }
    grid[r][c] = c2;
    for (int d = 0; d < 6; d++)
        floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main(){
    int cas=0;
    bool flag=false;
    while(scanf("%d",&R),R){
        getchar();
        flag=false;
        for(int i=0;i<R;i++) gets(grid[i]);
        C=R;
        memset(visited,false,sizeof visited);
        for(int i=0;i<R;i++)
            if(grid[0][i]=='b')
              floodfill(0,i,'b','.');

        for(int i=0;i<R;i++)
            if(grid[i][0]=='w')
              floodfill(i,0,'w','.');

        printf("%d %c\n",++cas,ans);
    }
    return 0;
}
