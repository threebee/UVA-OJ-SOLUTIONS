#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};
int grid[150][150];
int R,C;

int floodfill(int r, int c, int c1, int c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans=1;
    grid[r][c] = c2;
    for (int d = 0; d < 4; d++)
       ans+=floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main(){
    int n,m;
    char input[1000];
    while(scanf("%d",&R),R){
        C=R;
        getchar();
        memset(grid,0,sizeof 0);
        for(int i=0;i<R-1;i++){
            gets(input);
            char *pch;
            int x,y;
            pch=strtok(input," ");
            while(pch){
                x=atoi(pch);
                pch=strtok(NULL," ");
                y=atoi(pch);
                pch=strtok(NULL," ");
                grid[x-1][y-1]=i+1;
            }
        }

        for(int i=0;i<R;i++)
            for(int j=0;j<C;j++)
              if(grid[i][j]==0) grid[i][j]=R;

        bool flag=true;

        for(int i=0;i<R;i++) for(int j=0;j<C;j++){
            if(grid[i][j]!=0){
                if(floodfill(i,j,grid[i][j],0)!=R) flag=false;
            }
        }

        if(flag) printf("good\n");
        else     printf("wrong\n");

    }
    return 0;
}
