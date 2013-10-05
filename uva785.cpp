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
    //freopen("input.txt","r",stdin);
    while(1){
        R=C=0;
        if(gets(grid[R])==NULL) break;
        R++;
        while(gets(grid[R])!=NULL && grid[R++][0]!='_');
        for(int i=0;i<R;i++){
            for(int j=0;j<strlen(grid[i]);j++){
               if(grid[i][j]!=' ' && grid[i][j]!='X'){
                    char ch=grid[i][j];
                    grid[i][j]=' ';
                    floodfill(i,j,grid[i][j],ch);
               }
            }
        }
        for(int i=0;i<R-1;i++) for(int j=0;j<strlen(grid[i]);j++)
            if(grid[i][j]=='_') grid[i][j]=' ';
        for(int i=0;i<R;i++) puts(grid[i]);
    }
    return 0;
}

