#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

int main(){
  int t,i,j,l;
  bool flag;
  char str[2020];
  scanf("%d",&t);
  getchar();
  while(t--){
    gets(str);
    l=(int)strlen(str);
    for(i=l/3+1;i<l;i++){
        bool flag=true;
        for(j=0;j<i;j++)
            if(str[j]!=str[i+j]) flag=false;
        if(flag) break;
    }
    for(j=l;j<l+8;j++) printf("%c",str[j%i]);
    printf("...\n");
  }


  return 0;
}
