#include <iostream>
#include <cstdio>
#include <cmath>
#include <map>
#include <string>
using namespace std;
#define INF -1000000000

int main(){
    int Graph[110][110],D,C,S,cas=0;
    string U,V;
    while(scanf("%d %d",&C,&S),(C||S)){
        map <string,int> mp;
        for(int i=0;i<C;i++) for(int j=0;j<C;j++){
            if(i==j) Graph[i][j]=0;
            else     Graph[i][j]=INF;
        }
        int counter=0;
        for(int i=0;i<S;i++){
            cin>>U>>V>>D;
            if(!mp.count(U)) mp[U]=counter++;
            if(!mp.count(V)) mp[V]=counter++;
            Graph[mp[U]][mp[V]]=Graph[mp[V]][mp[U]]=D;
        }

        for(int k=0;k<C;k++)
            for(int i=0;i<C;i++)
              if(Graph[i][k]!=INF)
               for(int j=0;j<C;j++)
                  if(Graph[k][j]!=INF && i!=j)
                  Graph[i][j]=max(Graph[i][j],min(Graph[i][k],Graph[k][j]));

        cin>>U>>V;
        printf("Scenario #%d\n",++cas);
        printf("%d tons\n",Graph[mp[U]][mp[V]]);
        printf("\n");
    }
    return 0;
}

