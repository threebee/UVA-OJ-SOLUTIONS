#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int main(){
 int t;
 scanf("%d",&t);
 while(t--){
    int l,n,temp;
    scanf("%d %d",&l,&n);
    vector <int> v;
    for(int i=0;i<n;i++)
        scanf("%d",&temp),v.push_back(temp);
    sort(v.begin(),v.end());
    int maxi=INT_MIN,maxi1=INT_MIN;
    for(int i=0;i<(int)v.size();i++){
        int temp1,temp2;
        temp1=(v[i]<=l/2)?v[i]:l-v[i];
        //cout<<temp1<<" ";
        if(temp1>maxi)
            maxi=temp1;
        temp2=(v[i]<=l/2)?l-v[i]:v[i];
        if(temp2>maxi1)
            maxi1=temp2;
    }
    printf("%d %d\n",maxi,maxi1);

 }
 return 0;
}
