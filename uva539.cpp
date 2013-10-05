#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int  n,m;
bool visited[26][26],gr[26][26];

int backtrack(int id){
    int path=0;
    for(int i=0;i<n;i++){
        if(gr[id][i]  && !visited[id][i]){
            visited[id][i]=visited[i][id]=true;
            path=max(path,backtrack(i)+1);
            visited[id][i]=visited[i][id]=false;
        }
    }
    return path;
}

int main(){
   int tmp1,tmp2,path;
   while(scanf("%d %d",&n,&m),(n||m)){
        memset(gr,false,sizeof gr);
        memset(visited,false,sizeof visited);
        for(int i=0;i<m;i++){
            scanf("%d %d",&tmp1,&tmp2);
            gr[tmp1][tmp2]=gr[tmp2][tmp1]=true;
        }
        path=0;
        for(int i=0;i<n;i++) path=max(path,backtrack(i));
        printf("%d\n",path);
   }
   return 0;
}
