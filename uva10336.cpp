#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef pair<char,int> ci;

bool cmp(ci x,ci y){
    if(x.second==y.second)
       return x.first<y.first;
    return x.second>y.second;
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
    int cas=0,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&R,&C);
        for(int i=0;i<R;i++) scanf("%s",grid[i]);
        map <char,int> mp;
        for(int i=0;i<R;i++) for(int j=0;j<C;j++){
            if(grid[i][j]!='.'){
                mp[grid[i][j]]++;
                floodfill(i,j,grid[i][j],'.');
            }
        }
        vector <pair<char,int> > v(mp.begin(),mp.end());
        sort(v.begin(),v.end(),cmp);
        printf("World #%d\n",++cas);
        for(int i=0;i<v.size();i++){
             printf("%c: %d\n",v[i].first,v[i].second);
        }
    }
    return 0;
}
