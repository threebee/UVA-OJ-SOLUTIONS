#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int ,int> ii;
typedef vector <int> vi;


vector <pair<int ,ii> > edges;
vi pset,heavy_cycle;

void init(int N){
    pset.assign(N,0);
    for(int i=0;i<N;i++) pset[i]=i;
}

int find_set(int i){
    if(pset[i]==i) return pset[i];
    return pset[i]=find_set(pset[i]);
}

bool issameset(int i,int j){ return find_set(i)==find_set(j); }

void joinset(int i,int j){ pset[find_set(i)]=find_set(j); }

int main(){
    int n,m,a,b,dist;
    while(scanf("%d %d",&n,&m),(n||m)){
        init(n);
        edges.clear();
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&dist);
            ii tmp=make_pair(a,b);
            edges.push_back(make_pair(dist,tmp));
        }
        sort(edges.begin(),edges.end());
        heavy_cycle.clear();
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                joinset(edges[i].second.first,edges[i].second.second);
            }
            else heavy_cycle.push_back(edges[i].first);
        }

        if(!heavy_cycle.size()) printf("forest\n");
        else if(heavy_cycle.size()==1) printf("%d\n",heavy_cycle[0]);
        else{
            for(int i=0;i<heavy_cycle.size()-1;i++)
                printf("%d ",heavy_cycle[i]);
            printf("%d\n",heavy_cycle[heavy_cycle.size()-1]);
        }
    }
    return 0;
}
