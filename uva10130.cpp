#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int memo[1010][40],w[1010],v[1010],n,cap;

int val(int id,int weight){
   if(id==n || weight==0) return 0;
   if(memo[id][weight]!=-1) return memo[id][weight];
   if(w[id]>weight) return memo[id][weight]=val(id+1,weight);
   return memo[id][weight]=max(v[id]+val(id+1,weight-w[id]),val(id+1,weight));
}

int main(){
 int t,total,member;
 scanf("%d",&t);
 while(t--){
    memset(memo,-1,sizeof(memo));
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d %d",&v[i],&w[i]);
    total=0;
    scanf("%d",&member);
    for(int i=0;i<member;i++){
        scanf("%d",&cap);
        total+=val(0,cap);
    }
    printf("%d\n",total);
 }
 return 0;
}
