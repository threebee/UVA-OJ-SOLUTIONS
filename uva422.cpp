#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char a[110][110],ans[110];

int dr[]={-1,0,1,-1,1,-1,0,1};
int dc[]={1,1,1,0,0,-1,-1,-1};

bool found(int i,int j,int &i1,int &j1){
    int p,q,r;
    for(int k=0;k<8;k++){
        for(p=i,q=j,r=0;ans[r]!='\0';r++){
           if(a[p][q]==ans[r]){
                p+=dr[k];
                q+=dc[k];
           }
           else break;
        }
        if(ans[r]=='\0'){
          i1=p-dr[k]; j1=q-dc[k];
          return 1;
        }
    }
    return 0;
}

int main(){
 int i,j,i1,j1,n;
 bool flag=false;
 scanf("%d",&n);
 for(i=0;i<n;i++) scanf("%s",a[i]);
 while(scanf("%s",ans)){
    if(ans[0]=='0') break;
    flag=false;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==ans[0]){
               if(found(i,j,i1,j1)){
                  printf("%d,%d %d,%d\n",i+1,j+1,i1+1,j1+1);
                  flag=true;
               }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(!flag) printf("Not found\n");
 }
 return 0;
}
