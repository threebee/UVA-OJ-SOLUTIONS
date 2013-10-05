#include <cstdio>
using namespace std;

char grid[100][100];
int counts,n,m,offset;

void count_now(int a,int b){
    if(a>n-1 || b>m-1 || a<0 || b<0) return;
    char c=grid[a][b];
    grid[a][b]=++counts;
    switch(c){
        case 'N':  count_now(a-1,b);
            break;
        case 'W':  count_now(a,b-1);
            break;
        case 'S':  count_now(a+1,b);
            break;
        case 'E':  count_now(a,b+1);
            break;
        default:  offset=(int)c;
            break;
    }
}

int main(){
    int c;
    while(scanf("%d %d %d",&n,&m,&c)){
        if(n==0 && m==0 && c==0) break;
        counts=offset=100;
        for(int i=0;i<n;i++)
              scanf("%s",&grid[i]);
        count_now(0,c-1);
        if(offset==100) printf("%d step(s) to exit\n",counts-100);
        else          printf("%d step(s) before a loop of %d step(s)\n",offset-1-100,counts-offset);
    }
    return 0;
}
