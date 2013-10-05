#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;
#define INF 1000000000

int mat[50][50];

int main(){
   int n,m,cas=0;
   while(scanf("%d %d",&n,&m),n){
        map <int,string> rmp;
        string tmp;
        for(int i=0;i<n;i++){
            cin>>tmp;
            rmp[i]=tmp;
        }
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=INF;

        for(int i=0;i<n;i++) mat[i][i]=0;

        int a,b,c;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&a,&b,&c);
            a--; b--;
            mat[a][b]=mat[b][a]=c;
        }

        for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);

        int ans=INF,ans_i=0;
        for(int i=0;i<n;i++){
            long long int sum=0;
            for(int j=0;j<n;j++)
                sum+=mat[j][i];
            if(sum<ans){
                ans=sum;
                ans_i=i;
            }
        }
        printf("Case #%d : %s\n",++cas,rmp[ans_i].c_str());
   }
   return 0;
}
