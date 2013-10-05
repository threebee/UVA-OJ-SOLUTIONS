#include <cstdio>
#include <cstring>
#include <cstdlib>

int main(){
 int a,b,c,counts=0,ans;
 char str[100],op,*pch;
 while(gets(str)){
    if(strchr(str,'+')) op='+';
    else                op='-';
    pch=strtok(str,"+-=");  a=atoi(pch);
    pch=strtok(NULL,"+-="); b=atoi(pch);
    pch=strtok(NULL,"+-="); c=atoi(pch);
    if(op=='+') ans=a+b;
    else        ans=a-b;
    if(ans==c)  counts++;
 }
 printf("%d\n",counts);
 return 0;
}
