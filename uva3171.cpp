#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
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
    int n,m,a,b,dist,t,cas=0;
    char input[5000],*pch;
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        //getchar();
        init(n);
        edges.clear();
        for(int i=0;i<n;i++){
            gets(input);
            int node=0;
            for(pch=strtok(input,", "); pch ; pch=strtok(NULL,", ")){
                int val=atoi(pch);
                if(val){
                    ii tmp=make_pair(min(i,node),max(i,node));
                    edges.push_back(make_pair(val,tmp));
                }
                node++;
            }
        }
        sort(edges.begin(),edges.end());
        printf("Case %d:\n",++cas);
        int sum=0;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                printf("%c-%c %d\n",edges[i].second.first+65,edges[i].second.second+65,edges[i].first);
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
    }
    return 0;
}

