#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(){
 int temp,cas=1;
 bool blank=false;
 while(scanf("%d",&temp)){
  if(temp==-1) break;
  else{
    vector <int> v;
    v.push_back(temp);
    int temp2;
    while(scanf("%d",&temp2)){
       if(temp2==-1) break;
       else v.push_back(temp2);
    }
    vector <int> lds(v.size(),1);
    int maxi=1;
    for(int i=0;i<v.size();i++)
      for(int j=0;j<i;j++){
        if(v[j]>=v[i] && lds[i]<lds[j]+1){
                lds[i]=lds[j]+1;
                maxi=max(lds[i],maxi);
        }
     }
     if(blank) printf("\n");
     blank=true;
     printf("Test #%d:\n  maximum possible interceptions: %d\n",cas++,maxi);
  }
 }
 return 0;
}
