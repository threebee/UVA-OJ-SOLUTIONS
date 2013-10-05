#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
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
    int n,m,a,b,dist;
    while(scanf("%d %d",&n,&m),(n||m)){
        init(n);
        string str;
        map <string,int> mp;
        for(int i=0;i<n;i++){
            cin>>str;
            mp[str]=i;
        }
        edges.clear();
        for(int i=0;i<m;i++){
            string str1,str2;
            cin>>str1>>str2>>dist;
            a=mp[str1],b=mp[str2];
            ii tmp=make_pair(a,b);
            edges.push_back(make_pair(dist,tmp));
        }
        cin>>str;
        sort(edges.begin(),edges.end());
        int sum=0;
        int distinct_sets=n-1;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum+=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
                distinct_sets--;
            }
        }
        if(distinct_sets) printf("Impossible\n");
        else              printf("%d\n",sum);
    }
    return 0;
}


