/*
  submission error!!!
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

#define INF 1000000000
#define DFS_WHITE -1

typedef vector <int> vi;
typedef pair <int,int> ii;
typedef vector <ii> vii;

vector <vii> AdjList;

int dfs_counter,numSCC;
vi visited,dfs_num,dfs_low,S;

void tarjanSCC(int u){
    dfs_num[u]=dfs_low[u]=dfs_counter++;
    visited[u]=1;
    S.push_back(u);
    for(int j=0;j<(int)AdjList[u].size();j++){
        ii v=AdjList[u][j];
        if(dfs_num[v.first]==DFS_WHITE)
            tarjanSCC(v.first);
        if(visited[v.first])
            dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);
    }

    if(dfs_low[u]==dfs_num[u]){
       numSCC++;
       while(1){
         int v=S.back(); S.pop_back(); visited[v]=0;
         if(v==u) break;
       }
    }
}

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m),(n||m)){
        visited.assign(n,0);
        dfs_num.assign(n,DFS_WHITE);
        dfs_low.assign(n,0);
        dfs_counter=numSCC=0;

        AdjList.assign(n,vii());
        map <string,int> mp;

        char a[100],b[100],c[100],d[100];
        string tmp,tmp1;

        for(int i=0;i<n;i++){
             scanf("%s %s",a,b);
             a[strlen(a)-1]='\0';
             tmp=(string)a+(string)b;
             mp[tmp]=i;
        }

        for(int i=0;i<m;i++){
            scanf("%s %s",a,b);
            a[strlen(a)-1]='\0';
            tmp=(string)a+(string)b;
            scanf("%s %s",c,d);
            c[strlen(c)-1]='\0';
            tmp1=(string)c+(string)d;
            AdjList[mp[tmp]].push_back(ii(mp[tmp1],1));
        }

        S.clear();
        for(int i=0;i<n;i++)
          if(dfs_num[i]==DFS_WHITE)
            tarjanSCC(i);

        printf("%d\n",numSCC);
    }
    return 0;
}
