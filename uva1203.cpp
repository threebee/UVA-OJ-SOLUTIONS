#include <cstdio>
#include <queue>
#include <cstring>
#include <map>
using namespace std;

typedef pair<int,int> ii;

int main(){
 priority_queue <ii,vector<ii>,greater<ii> > pq;
 map <int,int> z;
 char command[50];
 int a,b,c;
 while(scanf("%s",command)){
    if(!strcmp(command,"#")) break;
    scanf("%d %d",&a,&b);
    pq.push(ii(b,a));
    z[a]=b;
 }
 scanf("%d",&c);
 while(c--){
    ii s=pq.top();
    pq.pop();
    printf("%d\n",s.second);
    pq.push(ii(s.first+z[s.second],s.second));
 }
 return 0;
}
