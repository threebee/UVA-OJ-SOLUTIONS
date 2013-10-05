#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int ,int> ii;
typedef vector <int> vi;

vector <pair<int ,ii> > edges;
vi pset;

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
    bool blank=false;
    int n,m,a,b,dist;
    int old_cost,new_cost;
    while(scanf("%d",&n)==1){
        init(n);
        edges.clear();
        old_cost=0;
        for(int i=0;i<n-1;i++){
            scanf("%d %d %d",&a,&b,&dist);
            old_cost+=dist;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&dist);
            a--,b--;
            ii tmp=make_pair(a,b);
            edges.push_back(make_pair(dist,tmp));
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&dist);
            a--,b--;
            ii tmp=make_pair(a,b);
            edges.push_back(make_pair(dist,tmp));
        }

        sort(edges.begin(),edges.end());
        new_cost=0;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                new_cost+=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        if(blank) printf("\n"); blank=true;
        printf("%d\n%d\n",old_cost,new_cost);
    }
    return 0;
}


