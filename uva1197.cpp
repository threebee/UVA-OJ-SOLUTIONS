#include <iostream>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef vector<int> vi;
vi pset,set_size;

void initSet(int N){
    pset.assign(N,0);
    set_size.assign(N,1);
    for(int i=0;i<N;i++) pset[i]=i;
}

int findset(int i) {
    if(pset[i]==i) return pset[i];
    else return pset[i]=findset(pset[i]);
}

bool isSameSet(int i,int j){
    return findset(i)==findset(j);
}

void unionSet(int i,int j){ pset[findset(i)]=findset(j); }


int main(){
   int n,m,k,a,b;
   while(scanf("%d %d",&n,&m),(n||m)){
        initSet(n);
        while(m--){
          scanf("%d", &k);
          scanf("%d", &a);
          k--;
          while (k--) {
            scanf("%d", &b);
            if(!isSameSet(a,b)){
                set_size[findset(b)]+=set_size[findset(a)];
                unionSet(a,b);
            }
            a=b;
          }
        }
        printf("%d\n", set_size[findset(0)]);
   }
   return 0;
}
