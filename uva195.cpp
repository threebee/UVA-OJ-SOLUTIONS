#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

bool cmp(char a,char b){
    int temp = tolower(a) - tolower(b);
    if(temp) return temp<0;
    return  a<b;
}

int main(){
   int t;
   char input[1000];
   scanf("%d",&t);
   while(t--){
        scanf("%s",input);
        sort(input,input+strlen(input),cmp);
        do{
            printf("%s\n",input);
        }while(next_permutation(input,input+strlen(input),cmp));
   }
   return 0;
}
