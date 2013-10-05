#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1000000000

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
    int n,m,a,b,dist,t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        init(n);
        edges.clear();
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&dist);
            ii tmp=make_pair(a,b);
            edges.push_back(make_pair(dist,tmp));
        }
        sort(edges.rbegin(),edges.rend());
        int sum=0,mini=INF;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum+=edges[i].first;
                mini=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        printf("Case #%d: %d\n",++cas,mini);
    }
    return 0;
}
