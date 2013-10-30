#include <cstdio>
#include <cstring>
typedef long long ll;
int n;
struct Matrix { int mat[110][110]; };

Matrix Multiply(Matrix a,Matrix b){
    Matrix ans;
    int i,j,k;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
          for(ans.mat[i][j]=0,k=0;k<n;k++)
             ans.mat[i][j]|=a.mat[i][k] & b.mat[k][j];
    return ans;
}

Matrix matPow(Matrix base,int p){
    Matrix ans;
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        ans.mat[i][j]=(i==j);
    while(p){
        if(p & 1) ans=Multiply(ans,base);
        base=Multiply(base,base);
        p>>=1;
    }
    return ans;
}

int main(){
    int c,l,s,e,d,a,b;
    Matrix input;
    while(scanf("%d %d",&c,&l),(c || l)){
        n=c;
        memset(input.mat,0,sizeof input.mat);
        for(int i=0;i<l;i++){
            scanf("%d %d",&a,&b);
            a--,b--;
            input.mat[a][b]=input.mat[b][a]=1;
        }
        scanf("%d %d %d",&s,&e,&d);
        input=matPow(input,d);
        s--,e--;
        if(input.mat[s][e]) printf("Yes, Teobaldo can travel.\n");
        else printf("No, Teobaldo can not travel.\n");
    }
    return 0;
}
