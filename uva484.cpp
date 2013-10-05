#include<cstdio>
#include<map>
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a;
    vector<int> b;
    map<int,int> c;
    while(scanf("%d",&a)==1){
        if(c.find(a)==c.end()){
            c[a]=1;
            b.push_back(a);
        }
        else{
            c[a]+=1;
        }
    }
    for(int i=0;i<b.size();i++){
        printf("%d %d\n",b[i],c[b[i]]);
    }
    return 0;
}
