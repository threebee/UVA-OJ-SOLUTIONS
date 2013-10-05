#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int visited[50];
int mat[50][50];
map <char,int> mp;
vector <char> order;
char ans[50];
bool g_flag;

bool check(int len,int u){
    for(int i=0;i<len;i++){
        if(mat[u][ans[i]-'A']) return false;
    }
    return true;
}

void backtrack(int len){
    if(len==order.size()){
        g_flag=false;
        for(int i=0;i<len-1;i++) printf("%c ",ans[i]);
        printf("%c",ans[len-1]);
        printf("\n");
        return ;
    }
    for(int i=0;i<order.size();i++){
        if(!visited[i] && check(len,order[i]-'A')){
            ans[len]=order[i];
            visited[i]=true;
            backtrack(len+1);
            visited[i]=false;
        }
    }
}

int main(){
    //freopen("out.txt","w",stdout);
    char input[1000];
    int t;
    scanf("%d",&t);
    getchar();
    while(t--){
        getchar();
        gets(input);
        order.clear();
        for ( int i=0; input[i]; i++ )
            if (isalpha(input[i])) order.push_back(input[i]);

        sort(order.begin(),order.end());

        gets(input);
        memset(mat,0,sizeof mat);
        char first,second;

        for(int i=0; input[i]; i++){
           if(isalpha(input[i])){
                first=input[i];
                i++;
                while(!isalpha(input [i])) i++;
                second=input [i];
                mat[first - 'A'][second - 'A']=1;
            }
        }
        memset(visited,false,sizeof visited);
        g_flag = true;
        backtrack(0);
        if(g_flag) printf("NO\n");
        if(t) printf("\n");
    }
    return 0;
}
