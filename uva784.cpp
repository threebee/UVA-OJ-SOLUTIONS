#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};
char grid[150][150];
int R,C;

void floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= strlen(grid[r])) return ;
    if (grid[r][c] != c1) return ;
    grid[r][c] = c2;
    for (int d = 0; d < 4; d++)
       floodfill(r + dr[d], c + dc[d], c1, c2);
}

int main(){
    int t;
    scanf("%d",&t);
    getchar();
    int pos_i,pos_j;
    while(t--){
        R=C=0;
        while(gets(grid[R]) && grid[R++][0]!='_'){
            C=strlen(grid[R-1]);
            for(int i=0;i<C;i++)
                if(grid[R-1][i]=='*') pos_i=R-1,pos_j=i,grid[R-1][i]=' ';
        }
        floodfill(pos_i,pos_j,' ','#');

        for(int i=0;i<R;i++) printf("%s\n",grid[i]);
    }
    return 0;
}
