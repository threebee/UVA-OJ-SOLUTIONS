#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
typedef vector <int> vi;

bool has(vi v, int e){
	for(int i=0; i<(int)v.size(); i++)
		if(v[i]==e) return true;
	return false;
}

int main(){
    int t,b,m,n;
    vector <vi> AdjList;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        AdjList.assign(n+1,vi());

        for(int i=1;i<=n;i++){
            scanf("%d",&m);
            while(m--){
                scanf("%d",&b);
                if(b>n) continue;
                if(!has(AdjList[i],b)) AdjList[i].push_back(b);
                if(!has(AdjList[b],i)) AdjList[b].push_back(i);
            }
        }

        int counts=0;
        queue <int> q;
        map <int,int> mp;

        for(int k=1;k<=n;k++){
            if(mp.count(k)) continue;
            q.push(k);
            int color[2]={0,0};
            bool isBipartite=true;
            mp[k]=0;
            color[0]++;
            while(!q.empty()){
                int u=q.front(); q.pop();
                for(int j=0;j<AdjList[u].size();j++){
                    if(!mp.count(AdjList[u][j])){
                        mp[AdjList[u][j]]=1-mp[u];
                        color[mp[AdjList[u][j]]]++;
                        q.push(AdjList[u][j]);
                    }
                    else if(mp[AdjList[u][j]]==mp[u]){
                        isBipartite=false;
                    }
                }
            }
            if(isBipartite){
                counts+=max(color[0],color[1]);
            }
        }
        printf("%d\n",counts);
    }
    return 0;
}
