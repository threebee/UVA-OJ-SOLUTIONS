#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;

int main(){
    int n,m,val;
    scanf("%d %d",&n,&m);
    map <string,int> mp;
    string tmp;
    while(n--){
        cin>>tmp>>val;
        mp[tmp]=val;
    }

    while(m--){
        char input[10000];
        int val=0;
        while(gets(input) && strcmp(input,".")!=0){
            char *pch;
            for(pch=strtok(input," ");pch;pch=strtok(NULL," ")){
                if(mp.count(pch)) val+=mp[pch];
            }
        }
        printf("%d\n",val);
    }
    return 0;
}
