#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define INF 1000000000

typedef pair<int ,int> ii;
typedef vector <int> vi;

vector <pair<int ,ii> > edges;
vi pset,selected_edges;

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
        selected_edges.clear();
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&dist);
            a--,b--;
            ii tmp=make_pair(a,b);
            edges.push_back(make_pair(dist,tmp));
        }
        sort(edges.begin(),edges.end());
        int best=0,sbest=INF;
        int d_set=n-1;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                best+=edges[i].first;
                d_set--;
                selected_edges.push_back(i);
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        if(d_set){
            printf("Case #%d : No way\n",++cas);
            continue;
        }

        bool taken[edges.size()];
        memset(taken,false,sizeof taken);

        for(int j=0;j<selected_edges.size();j++){
            init(n);
            int span=0;
            taken[selected_edges[j]]=true;
            d_set=n-1;
            for(int i=0;i<edges.size();i++){
              if(!taken[i])
              if(!issameset(edges[i].second.first,edges[i].second.second)){
                 span+=edges[i].first;
                 d_set--;
                 joinset(edges[i].second.first,edges[i].second.second);
              }
            }
            taken[selected_edges[j]]=false;
            if(!d_set)
            sbest=min(sbest,span);
        }
        printf("Case #%d : ",++cas);
        if(sbest!=INF) printf("%d\n",sbest);
        else printf("No second way\n");
    }
    return 0;
}

