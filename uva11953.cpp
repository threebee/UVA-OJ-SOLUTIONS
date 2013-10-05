#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dr[] = {1,1,0,-1,-1,-1, 0, 1};
int dc[] = {0,1,1, 1, 0,-1,-1,-1};
char grid[150][150];
int R,C;

void floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c]=='.') return ;
    grid[r][c] = c2;
    for (int d = 0; d < 8; d++)
       floodfill(r + dr[d], c + dc[d], c1, c2);
}


int main(){
    int t,cas=0,cnt;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&R);
        C=R;
        getchar();
        for(int i=0;i<R;i++) gets(grid[i]);
        cnt=0;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++){
            if(grid[i][j]=='x'){
                floodfill(i,j,'x','.');
                cnt++;
            }
        }
        printf("Case %d: %d\n",++cas,cnt);
    }
    return 0;
}
