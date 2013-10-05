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

bool check(int len,int u){
    for(int i=0;i<len;i++){
        if(mat[u][ans[i]-'a']) return false;
    }
    return true;
}

void backtrack(int len){
    if(len==order.size()){
        for(int i=0;i<len;i++) printf("%c",ans[i]);
        printf("\n");
        return ;
    }
    for(int i=0;i<order.size();i++){
        if(!visited[i] && check(len,order[i]-'a')){
            ans[len]=order[i];
            visited[i]=true;
            backtrack(len+1);
            visited[i]=false;
        }
    }
}


int main(){
    char input[1000];
    bool flag=false;

    while(gets(input)){
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
                mat[first - 'a'][second - 'a']=1;
            }
        }
        if(flag) printf("\n");
        flag=true;
        memset(visited,false,sizeof visited);
        backtrack(0);
    }
    return 0;
}
