#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef vector <int> vi;

int main(){
    int t,a,b,m,n;
    vector <vi> AdjList;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        AdjList.assign(n,vi());
        for(int i=0;i<m;i++){
            scanf("%d %d",&a,&b);
            AdjList[a].push_back(b);
            AdjList[b].push_back(a);
        }
        int counts=0;
        queue <int> q;
        map <int,int> mp;

        for(int k=0;k<n;k++){
            if(mp.count(k)) continue;
            q.push(k);
            int color[2]={0,0};
            bool isBipartite=true;
            mp[k]=0;
            color[0]++;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int i=0;i<AdjList[u].size();i++){
                    if(!mp.count(AdjList[u][i])){
                        mp[AdjList[u][i]]=1-mp[u];
                        color[mp[AdjList[u][i]]]++;
                        q.push(AdjList[u][i]);
                    }
                    else if(mp[AdjList[u][i]]==mp[u])
                        isBipartite=false;
                }
            }
            if(!isBipartite) {
                counts=-1;
                break;
            }
            else {
                counts+=(color[0]>0 && color[1]>0) ? min(color[0],color[1])
                        : max(color[0],color[1]);
            }
        }
        printf("%d\n",counts);
    }
    return 0;
}
