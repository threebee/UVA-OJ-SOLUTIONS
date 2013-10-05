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

int mabs(int x){
    if(x>0) return x;
    return -x;
}

int dist(int a,int b){
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=min( abs(a%10 - b%10) , 10-abs(a%10 - b%10) );
        a/=10,b/=10;
    }
    return sum;
}


int main(){
    int n,m,a,b,t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        edges.clear();
        int input[n];
        for(int i=0;i<n;i++) scanf("%d",&input[i]);
        int sum=INF;
        for(int i=0;i<n;i++) sum=min(sum,dist(0,input[i]));

        for(int i=0;i<n;i++)
          for(int j=i+1;j<n;j++){
            ii tmp=make_pair(i,j);
            edges.push_back(make_pair(dist(input[i],input[j]),tmp));
          }
        sort(edges.begin(),edges.end());

        for(int i=0;i<edges.size();i++){
            if(!issameset(edges[i].second.first,edges[i].second.second)){
                sum+=edges[i].first;
                joinset(edges[i].second.first,edges[i].second.second);
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}

