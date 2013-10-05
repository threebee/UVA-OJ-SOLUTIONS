#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef vector<int> vi;

vi pset,set_size;

void init(vi &pset,vi &set_size,int n){
    pset.assign(n,0);
    set_size.assign(n,0);
    for(int i=0;i<n;i++)
       pset[i]=i,set_size[i]=1;
}

int find_set(int i){
    if(pset[i]==i) return i;
    else return pset[i]=find_set(pset[i]);
}

bool same_set(int i,int j){ return find_set(i)==find_set(j); }

void union_set(int i,int j){ pset[find_set(i)]=find_set(j); }

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,counts=0;
        scanf("%d",&n);
        init(pset,set_size,2*n+1);
        map <string,int> mp;
        string a,b;
        for(int i=0;i<n;i++){
            cin>>a>>b;
            if(!mp.count(a)) mp[a]=counts++;
            if(!mp.count(b)) mp[b]=counts++;
            if(!same_set(mp[a],mp[b])){
                set_size[find_set(mp[b])]+=set_size[find_set(mp[a])];
                union_set(mp[a],mp[b]);
            }
            printf("%d\n",set_size[find_set(mp[a])]);
        }
    }
    return 0;
}
