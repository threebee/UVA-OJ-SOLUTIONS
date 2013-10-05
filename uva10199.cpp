#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define DFS_WHITE -1

typedef vector <int> vi;

vector <vi> AdjList;
int V,rootnode,rootchildren,counter;
vi dfs_num,dfs_parent,dfs_low,articulation_vertex;

void articulationPoint(int u){
    dfs_num[u]=dfs_low[u]=counter++;
    for(int j=0;j<(int)AdjList[u].size();j++){
        int v=AdjList[u][j];
        if(dfs_num[v]==DFS_WHITE){
            dfs_parent[v]=u;
            if(u == rootnode) rootchildren++;

            articulationPoint(v);

            if(dfs_low[v]>=dfs_num[u])
                articulation_vertex[u]=1;
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
}

int main(){
    //freopen("output.txt","w",stdout);
    bool blank=false;
    int cas=0;
    while(scanf("%d",&V),V){
        map <string,int> mp;
        map <int,string> rmp;
        string tmp1,tmp2;
        for(int i=0;i<V;i++)
          cin>>tmp1,mp[tmp1]=i,rmp[i]=tmp1;
        int E;
        scanf("%d",&E);
        AdjList.assign(V,vi());
        for(int i=0;i<E;i++){
            cin>>tmp1>>tmp2;
            AdjList[mp[tmp1]].push_back(mp[tmp2]);
            AdjList[mp[tmp2]].push_back(mp[tmp1]);
        }
        dfs_num.assign(V,DFS_WHITE); dfs_parent.assign(V,-1);
        dfs_low.assign(V,0);  articulation_vertex.assign(V,0);
        counter=0;

        for(int i=0;i<V;i++){
            if(dfs_num[i]==DFS_WHITE){
                rootnode=i; rootchildren=0;
                articulationPoint(i);
                articulation_vertex[rootnode]=(rootchildren>1);
            }
        }
        if(blank) printf("\n"); blank=true;
        vector <string> vs;
        int ans=0;
        for(int i=0;i<V;i++)
            if(articulation_vertex[i]) ans++,vs.push_back(rmp[i]);
        printf("City map #%d: %d camera(s) found\n",++cas,ans);
        sort(vs.begin(),vs.end());
        for(int i=0;i<vs.size();i++)
            printf("%s\n",vs[i].c_str());
    }
    return 0;
}
