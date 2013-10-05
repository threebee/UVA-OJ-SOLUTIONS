#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

vector<vii> AdjList;
vi dfs_num;

#define DFS_WHITE -1
#define DFS_BLACK  1
int z;
bool flag;

void dfs(int u){
    dfs_num[u]=DFS_BLACK;
    for(int j=0;j<(int)AdjList[u].size();j++){
        ii v=AdjList[u][j];
        if(v.first==z) flag=true;
        if(dfs_num[v.first]==DFS_WHITE)
            dfs(v.first);
    }
}

void self_loop(int u){
    for(int j=0;j<(int)AdjList[u].size();j++){
        ii v=AdjList[u][j];
        if(v.first==u){
            flag=true;
        }
    }
}

int main(){
    int V,id,weight,total_neb;

    while(scanf("%d",&V)){
        if(V==0) break;
        AdjList.clear();  AdjList.assign(V,vii());
        dfs_num.clear();  dfs_num.assign(V,DFS_WHITE);
        int i;
        while(scanf("%d",&i)){
            if(i==0) break;
            int j;
            while(scanf("%d",&j)){
                if(j==0) break;
                AdjList[i-1].push_back(ii(j-1,1));
            }
        }
        int k,n;
        scanf("%d",&k);
        while(k--){
            scanf("%d",&n);
            dfs_num.assign(V,DFS_WHITE);
            z=n-1; flag=false;
            dfs(n-1);
            int counts=0;
            for(int t=0;t<V;t++)
                if(dfs_num[t]==DFS_WHITE) counts++;
            self_loop(n-1);
            if(!flag) counts++,dfs_num[n-1]=DFS_WHITE;
            printf("%d",counts);

            for(int t=0;t<V;t++){
                if(dfs_num[t]==DFS_WHITE)
                    printf(" %d",t+1);
            }
            printf("\n");
        }
    }
    return 0;
}
