#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>
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
    int counter,t,n,m,dist;
    string a,b;
    map <string,int> mp;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        init(n);
        edges.clear();
        mp.clear();
        counter=0;
        for(int i=0;i<m;i++){
            cin>>a>>b>>dist;
            if(!mp.count(a)) mp[a]=counter++;
            if(!mp.count(b)) mp[b]=counter++;

            ii tmp=make_pair(mp[a],mp[b]);
            edges.push_back(make_pair(dist,tmp));
        }
        sort(edges.begin(),edges.end());
        int sum=0;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum+=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        printf("%d\n",sum);
        if(t) printf("\n");
    }
    return 0;
}
