//submission error

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector <int> topo,visited;
int mat[1010][1010];
int n,m;
bool flag;

void dfs(int u){
    visited[u]=1;
    for(int j=1;j<=n;j++){
        if(mat[u][j]){
            if(!visited[j]) dfs(j);
            else            flag=true;
        }
    }
    topo.push_back(u);
}

int main(){
    while(scanf("%d %d",&n,&m),(n||m)){
        memset(mat,0,sizeof mat);
        int a,b;
        for(int i=0;i<m;i++)
            scanf("%d %d",&a,&b),mat[a][b]=1;
        topo.clear();
        visited.assign(n+1,0);
        flag=false;

        for(int i=1;i<=n;i++)
            if(!visited[i]) dfs(i);

        reverse(topo.begin(),topo.end());

        if(flag) printf("IMPOSSIBLE\n");
        else{
            for(int i=0;i<topo.size();i++)
                printf("%d\n",topo[i]);
        }
    }
    return 0;
}
