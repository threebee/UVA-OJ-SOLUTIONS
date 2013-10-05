#include <cstring>
#include <list>
#include <cstdio>
#include <iterator>
using namespace std;

int main(){
 char text[100000];
 while(scanf("%s",text)!=EOF){
        list <char> ls;
        list <char>::iterator j;
        j=ls.begin();
        int len=strlen(text);
        for(int i=0;i<len;i++){
            if(text[i]=='[') j=ls.begin();
            else if(text[i]==']') j=ls.end();
            else ls.insert(j,text[i]);
        }
        for(j=ls.begin();j!=ls.end();j++)
            printf("%c",*j);
        printf("\n");
 }
 return 0;
}
