#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int v[1000],memo[1000][1000],n;

int val(int id,int weight){
   if(id==n || weight==0) return 0;
   if(memo[id][weight]!=-1) return memo[id][weight];
   if(v[id]>weight) return memo[id][weight]=val(id+1,weight);
   return memo[id][weight]=max(v[id]+val(id+1,weight-v[id]),val(id+1,weight));
}

int main(){
 int t,i,total;
 char *ptr,str[10000];
 scanf("%d",&t);
 getchar();
 while(t--){
   total=0,n=0;
   gets(str);
   for(ptr=strtok(str, " "); ptr; ptr = strtok(NULL, " ")){
      i=atoi(ptr);
      v[n++]=i;
      total+=i;
   }
   memset(memo,-1,sizeof(memo));
   if(total%2 || total==0){
      printf("NO\n");
      continue;
   }
   int sum=total/2;
   if(val(0,sum)==sum) printf("YES\n");
   else                printf("NO\n");
 }
 return 0;
}
