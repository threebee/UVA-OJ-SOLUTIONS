#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

int main(){
 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 vector <int> v;
 int temp,i,j,maxi=0;
 while(scanf("%d",&temp)==1)  v.push_back(temp);
 vector <int> lis(v.size()+2,INT_MAX);
 vector <int> ans(v.size(),0),final_ans;
 lis[0]=INT_MIN;


 for(i=0;i<(int)v.size();i++){
    j=int(upper_bound(lis.begin(),lis.end(),v[i])-lis.begin());
    if(binary_search (lis.begin(), lis.end(), v[i])) j-=1;
    if(lis[j-1]<v[i] && v[i]<=lis[j]){
        lis[j]=v[i];
        if(maxi < j) maxi=j;
    }
    ans[i]=j;
 }

  j=(int)v.size();
  temp=maxi;
  while(maxi){
     while(j>-1){
        if(ans[j]==maxi){ final_ans.push_back(v[j]); break; }
        j--;
     }
     maxi--;
  }

 printf("%d\n-\n",temp);
 for(int i=final_ans.size()-1;i>=0;i--) printf("%d\n",final_ans[i]);

 return 0;
}
