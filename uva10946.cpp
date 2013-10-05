#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct alpha { char ch; int val;};

bool cmp(alpha x,alpha y){
    if(x.val==y.val)
       return x.ch<y.ch;
    return x.val>y.val;
}

int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};
char grid[500][500];
int R,C;

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C) return 0;
    if (grid[r][c] != c1) return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int d = 0; d < 4; d++)
        ans += floodfill(r + dr[d], c + dc[d], c1, c2);
    return ans;
}

int main(){
    //freopen("input.txt","r",stdin);
    int cas=0;
    while(scanf("%d %d",&R,&C),(R||C)){
        for(int i=0;i<R;i++) scanf("%s",grid[i]);
        vector <alpha> v;
        alpha tmp;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++){
            if(grid[i][j]!='.'){
                tmp.ch=grid[i][j];
                tmp.val=floodfill(i,j,grid[i][j],'.');
                v.push_back(tmp);
            }
        }
        sort(v.begin(),v.end(),cmp);
        printf("Problem %d:\n",++cas);
        for(int i=0;i<v.size();i++){
            printf("%c %d\n",v[i].ch,v[i].val);
        }
    }
    return 0;
}

