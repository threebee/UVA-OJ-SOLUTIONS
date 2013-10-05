#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main(){
  char s[10010][30],temp[30];
  int n,i,t;
  bool flag;
  scanf("%d",&n);
  for(i=0;i<n;i++) scanf("%s",s[i]);
  scanf("%d",&t);
  while(t--){
      flag=false;
      scanf("%s",temp);
      for(i=0;i<n;i++){
        if(!strcmp(s[i],temp)){
            flag=true;
            break;
        }
      }
      if(flag){
        printf("%s is correct\n",temp);
        continue;
      }
      for(i=0;i<n;i++){
        char *a=temp,*b=s[i];
        while(*a==*b) a++,b++;
        if(*a && !strcmp(a+1,b)) {flag=true; break; }
        if(*b && !strcmp(a,b+1)) {flag=true; break; }
        if(*a && *b && !strcmp(a+1,b+1)){ flag=true; break; }
        if(a[0] && b[0] && a[0]==b[1] && a[1]==b[0] && !strcmp(a+2,b+2)){ flag=true; break; }
      }
      if(flag){
        printf("%s is a misspelling of %s\n",temp,s[i]);
        continue;
      }
      printf("%s is unknown\n",temp);
  }
  return 0;
}
