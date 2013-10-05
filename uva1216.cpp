#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int ,int> ii;
typedef vector <int> vi;

vector <pair<double ,ii> > edges;
vi pset,vx,vy;

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
    int n,m,a,b,t;
    double dist;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&m);
        edges.clear(); vx.clear(); vy.clear();
        while(1){
            scanf("%d",&a);
            if(a == -1) break;
            scanf("%d",&b);
            vx.push_back(a); vy.push_back(b);
        }
        n=vx.size();
        init(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist=hypot( (vx[i]-vx[j]),(vy[i]-vy[j]) );
                ii tmp=make_pair(i,j);
                edges.push_back(make_pair(dist,tmp));
            }
        }

        sort(edges.begin(),edges.end());
        double sum=0.0;
        int d_set=n;
        bool flag=true;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum=max(sum,edges[i].first);
                d_set--;
                joinset(edges[i].second.first,edges[i].second.second);
            }

            if(d_set == m){
                sum= edges[i].first;
                flag=false;
                break;
            }
        }
        if(flag) sum=edges[edges.size() - 1].first;
        printf("%d\n",(int)ceil(sum));
    }
    return 0;
}

