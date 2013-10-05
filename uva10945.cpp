#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    char input[1000000];
    while(gets(input),strcmp(input,"DONE")){
        char *pch;
        string t="";
        for(pch=strtok(input,".,!? ");pch;pch=strtok(NULL,".,!? "))  t+=pch;

        for(int i=0;i<t.length();i++)
             t[i]=tolower(t[i]);

        string s=t;
        reverse(t.begin(),t.end());

        if(s==t) printf("You won't be eaten!\n");
        else     printf("Uh oh..\n");
    }
    return 0;
}
