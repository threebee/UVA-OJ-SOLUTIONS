#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
 int t;
 bool flag=false;
 scanf("%d",&t);
 getchar();
 char c[10];
 gets(c);
 while(t--){
   vector <int> v;
   while(gets(c) && strlen(c))
       v.push_back(atoi(c));

   vector <int> lis(v.size(),1);
   int maxi=1;
   for(int i=0;i<v.size();i++)
     for(int j=0;j<i;j++)
        if(v[j]<v[i] && lis[i]<lis[j]+1)
            lis[i]=lis[j]+1,maxi=max(maxi,lis[i]);
    if(flag) printf("\n");
    flag=true;
   printf("Max hits: %d\n",maxi);
   int tmp=maxi;
   vector<int> indexes;
   for(int i=lis.size()-1;i>=0;i--)
   if(lis[i]==tmp ){
      indexes.push_back(i);
      --tmp;
   }
   reverse(indexes.begin(),indexes.end());
   for(int i=0;i<indexes.size();i++) printf("%d\n",v[indexes[i]]);
 }
 return 0;
 }
