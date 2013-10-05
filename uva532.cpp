/*
  BFS on implicit graph
  DFS approach will lead to time limit
*/

#include <cstdio>
#include <queue>
#include <map>
using namespace std;

struct node{ int i,j,k; };

int depth,n,m;
char matrix[35][35][35];

int d_i[]={0,0,1,-1,0,0};
int d_j[]={1,-1,0,0,0,0};
int d_k[]={0,0,0,0,1,-1};

bool operator < (node x,node y){
    if(x.k==y.k)
        if(x.i==y.i) return x.j<y.j;
        else return  x.i<y.i;
    return x.k<y.k;
}

bool operator == (node x,node y){
    if(x.k==y.k && x.i==y.i && x.j==y.j) return true;
    return false;
}

node make_node(int i,int j,int k){
    node s;
    s.i=i; s.j=j; s.k=k;
    return s;
}

node make_node(node u,int i,int j,int k){
    u.i+=i;  u.j+=j;  u.k+=k;
    return u;
}

bool check(node u,int i,int j,int k){
     u.i+=i;  u.j+=j;  u.k+=k;
     if( u.i<0 || u.i>=n || u.j<0 || u.j>=m || u.k<0 || u.k>=depth ) return false;
     if(matrix[u.k][u.i][u.j]=='#') return false;
     return true;
}

int main(){
    int S_i,S_j,S_k,E_i,E_j,E_k;

    while(scanf("%d %d %d",&depth,&n,&m),(depth||n||m)){

        for(int k=0;k<depth;k++){
            for(int i=0;i<n;i++){
                scanf("%s",&matrix[k][i]);
                for(int j=0;j<m;j++){
                  if(matrix[k][i][j]=='S') S_i=i,S_j=j,S_k=k;
                  if(matrix[k][i][j]=='E') E_i=i,E_j=j,E_k=k;
                }
            }
        }

        node s=make_node(S_i,S_j,S_k);
        node e=make_node(E_i,E_j,E_k);
        map<node, int> dist; dist[s] = 0;
        queue <node> q; q.push(s);
        while (!q.empty()) {
            node u = q.front(); q.pop();
            for(int i=0;i<6;i++){
                if(check(u,d_i[i],d_j[i],d_k[i])){
                    node tmp=make_node(u,d_i[i],d_j[i],d_k[i]);
                    if(!dist.count(tmp)){
                        dist[tmp]=dist[u]+1;
                        q.push(tmp);
                    }
                    if(tmp==e) break;
                }
            }
        }

        if(dist.count(e))  printf("Escaped in %d minute(s).\n",dist[e]);
        else               printf("Trapped!\n");

    }
    return 0;
}
