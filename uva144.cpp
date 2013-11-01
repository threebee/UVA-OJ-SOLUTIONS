#include <cstdio>
#include <queue>
using namespace std;

typedef pair <int,int> ii;
typedef queue <ii> qii;

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k),(n||k)){
        qii q;
        for(int i=1;i<=n;i++){
            q.push(ii(i,40));
        }

        while(!q.empty()){
           for(int i=1; i<=k; i++){
              int limit=i;
              while (limit && !q.empty()){
                ii tmp = q.front(); q.pop();
                if(tmp.second > limit) {
                     tmp.second-=limit;
                     limit=0;
                     q.push(tmp);
                }
                else{
                    limit-=tmp.second;
                    printf("%3d",tmp.first);
                }
              }
            }
        }
        printf("\n");
    }
    return 0;
}
