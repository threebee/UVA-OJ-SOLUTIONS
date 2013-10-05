#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int ,int> ii;
typedef vector <int> vi;

vector <pair<double ,ii> > edges;
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
    int t,n;
    bool flag=false;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        edges.clear();
        vector <double> v1,v2;
        double tmp1,tmp2;
        for(int i=0;i<n;i++){
            cin>>tmp1>>tmp2;
            v1.push_back(tmp1);
            v2.push_back(tmp2);
        }

        for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            double weight=sqrt((v1[i]-v1[j])*(v1[i]-v1[j]) + (v2[i]-v2[j])*(v2[i]-v2[j]));
             ii tmp=make_pair(i,j);
            edges.push_back(make_pair(weight,tmp));
        }
        sort(edges.begin(),edges.end());
        double sum=0;
        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum+=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        if(flag) printf("\n"); flag=true;
        printf("%0.2lf\n",sum);
    }
    return 0;
}
