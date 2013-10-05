#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

const int MAXN = 1000010;
vector<int> AdjList[MAXN];

int main(){
 int n,m,k,v,counts,temp;
 while(scanf("%d %d",&n,&m)!=EOF){
    counts=0;
    for(int i=1;i<MAXN;i++)
        AdjList[i].clear();

    while(n--){
        counts++;
        scanf("%d",&temp);
        AdjList[temp].push_back(counts);
    }
    while(m--){
        scanf("%d %d",&k,&v);
        if(k>AdjList[v].size()) printf("0\n");
        else printf("%d\n",AdjList[v][k-1]);
    }
 }
 return 0;
}
