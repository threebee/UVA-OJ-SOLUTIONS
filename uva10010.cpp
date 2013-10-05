#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;

char a[110][110],ans[110];

int dr[]={-1,0,1,-1,1,-1,0,1};
int dc[]={1,1,1,0,0,-1,-1,-1};

bool found(int i,int j){
    int p,q,r;
    for(int k=0;k<8;k++){
        for(p=i,q=j,r=0;ans[r]!='\0';r++){
           if(a[p][q]==ans[r]){
                p+=dr[k];
                q+=dc[k];
           }
           else break;
        }
        if(ans[r]=='\0') return 1;
    }
    return 0;
}

int main(){
 int i,j,n,m,t,t1;
 bool flag=false;
 scanf("%d",&t);
 while(t--){
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++) scanf("%s",a[i]);
    for(i=0;i<n;i++)
       for(j=0;j<m;j++)
          a[i][j]=tolower(a[i][j]);
    scanf("%d",&t1);
    while(t1--){
      scanf("%s",ans);
      for(i=0;i<strlen(ans);i++) ans[i]=tolower(ans[i]);
      flag=false;
      for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(a[i][j]==ans[0]){
               if(found(i,j)){
                  printf("%d %d\n",i+1,j+1);
                  flag=true;
               }
            }
            if(flag) break;
        }
        if(flag) break;
    }
 }
 if(t) printf("\n");
 }
 return 0;
}

