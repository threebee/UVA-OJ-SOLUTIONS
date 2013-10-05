#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int mat[30][30];
vector <int> topo,visited,in;

void dfs(int u){
    visited[u]=1;
    for(int j=0;j<26;j++){
        if(mat[u][j]){
            if(!visited[j])
                dfs(j);
        }
    }
    topo.push_back(u);
}

int main(){
    visited.assign(30,0);
    in.assign(30,0);
    memset(mat,0,sizeof mat);
    char s[30],ps[30];
    scanf("%s", ps);
	while (scanf("%s", s), strcmp(s, "#") != 0) {
		for (int i = 0; i < (int) strlen(s) && i < (int) strlen(ps); i++) {
			if (ps[i] != s[i]) {
				in[ps[i] - 'A']=1;
				in[s[i] - 'A']=1;
				mat[ps[i] - 'A'][s[i] - 'A']=1;
				break;
			}
		}
		strcpy(ps, s);
	}
    topo.clear();
    for(int i=0;i<26;i++){
        if(!visited[i] && in[i])
            dfs(i);
    }
    reverse(topo.begin(),topo.end());
    for(int i=0;i<topo.size();i++)
        printf("%c",char(topo[i]+'A'));
    printf("\n");
    return 0;
}
