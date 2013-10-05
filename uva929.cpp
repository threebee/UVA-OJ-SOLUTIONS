#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define INF 1000000000

int N,M,dist[1010][1010],grid[1010][1010];

typedef pair <int,int> ii;
typedef pair <int,ii> iii;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool check(int x,int y){
    if( x<0 || x>=N || y<0 || y>=M ) return false;
    return true;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&N,&M);

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
              dist[i][j]=INF;

        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                scanf("%d",&grid[i][j]);

        priority_queue < iii , vector <iii> ,greater <iii> > pq;
        pq.push(make_pair (grid[0][0],ii(0,0)));
        dist[0][0]=grid[0][0];

        while(!pq.empty()){
            iii node=pq.top(); pq.pop();
            int d=node.first;
            int x=node.second.first;
            int y=node.second.second;

            if(dist[x][y] == d)
              for(int i=0;i<4;i++){
                 int nx=x+dx[i];
                 int ny=y+dy[i];

                 if(check(nx,ny)){
                     if(dist[nx][ny] > dist[x][y] + grid[nx][ny]){
                        dist[nx][ny]=dist[x][y]+grid[nx][ny];
                        pq.push(make_pair(dist[nx][ny],ii(nx,ny)));
                     }
                 }
              }
        }
        printf("%d\n", dist[N-1][M-1]);
    }
    return 0;
}
