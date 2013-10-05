#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

struct seat { int val,id; };
struct team { int val,id; };

bool cmp (seat a,seat b) { return a.val>b.val; };
bool cmp1 (team a,team b) { return a.val>b.val; };

int main(){
 int m,n,i,j,tmp,tmp1;
 seat s[75];
 team t[75];
 bool flag;
 vvi ans;
 while(scanf("%d %d",&m,&n),(m | n)){
    ans.assign(m,vi());
    flag=true;
    for(i=0;i<m;i++) scanf("%d",&t[i].val),t[i].id=i+1;
    for(i=0;i<n;i++) scanf("%d",&s[i].val),s[i].id=i+1;
    sort(t,t+m,cmp1);
    sort(s,s+n,cmp);
    for(i=0;i<m;i++){
        tmp=t[i].val;
        for(j=0;j<n;j++){
            if(!tmp) break;
            if(s[j].val){
                ans[t[i].id-1].push_back(s[j].id);
                tmp--;
                s[j].val--;
            }
            else continue;
        }
        if(tmp){
            flag=false;
            break;
        }
    }
    if(!flag) printf("0\n");
    else{
        printf("1\n");
        for(i=0;i<m;i++){
            sort(ans[i].begin(),ans[i].end());
            for(j=0;j<ans[i].size();j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
    }
 }
 return 0;
}
