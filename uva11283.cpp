#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

char a[5][5];
bool taken[5][5];

int dr[]={-1,0,1,-1,1,-1,0,1};
int dc[]={1,1,1,0,0,-1,-1,-1};
int sc[]={1,1,2,3,5};

bool check(int x,int y){
    if(x>=0 && x<4 && y>=0 && y<4 && !taken[x][y]) return true;
    return false;
}

bool found(int i,int j,int id,string ans){
    if(id==ans.length()) return true;
    bool flag=false;
    taken[i][j]=true;
    for(int k=0;k<8;k++){
        if(check(i+dr[k],j+dc[k])){
            if(a[i+dr[k]][j+dc[k]]==ans[id])  flag=found(i+dr[k],j+dc[k],id+1,ans);
        }
        if(flag) break;
    }
    taken[i][j]=false;
    return flag;
}

int main(){
 int t,t1,i,j,score,length,counts=0;
 bool flag;
 char ans[17];
 scanf("%d",&t);
 while(t--){
  score=0;
  for(i=0;i<4;i++) scanf("%s",a[i]);
  scanf("%d",&t1);
  while(t1--){
      scanf("%s",ans);
      flag=false;
      for(i=0;i<4;i++){
        for(j=0;j<4;j++){
           if(a[i][j]==ans[0]){
              memset(taken,false,sizeof(taken));
              if(found(i,j,1,ans)){
                  length=strlen(ans);
                  if(length>=8) score+=11;
                  else          score+=sc[length-3];
                  flag=true;
               }
            }
            if(flag) break;
        }
        if(flag) break;
    }
  }
  printf("Score for Boggle game #%d: %d\n",++counts,score);
 }
 return 0;
}
