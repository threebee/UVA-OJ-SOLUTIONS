#include <cmath>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

map <string,int> mp;
map <int,string> mp1;
vector <int> visited,in;

int n,m;
int graph[210][210];

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int cas=0;
    while(scanf("%d",&n)==1){
        string tmp;
        mp.clear(); mp1.clear();
        visited.assign(n+1,0);
        in.assign(n+1,0);

        for(int i=1;i<=n;i++){
            cin>>tmp;
            mp[tmp]=i;
            mp1[i]=tmp;
        }
        memset(graph,0,sizeof graph);
        scanf("%d",&m);
        while(m--){
            string a,b;
            cin>>a>>b;
            if(!graph[mp[a]][mp[b]]){
                graph[mp[a]][mp[b]]=1;
                in[mp[b]]++;
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",++cas);
        bool done = false;
        while(!done){
            done=true;
            for(int i=1;i<=n;i++){
                if(!visited[i] && in[i]==0){
                    done=false;
                    visited[i]=1;
                    printf(" %s",mp1[i].c_str());
                    for(int j=1;j<=n;j++)
                        if(graph[i][j])in[j]--;
                    i=0;
                }
            }
        }
        printf(".\n\n");
    }
    return 0;
}
