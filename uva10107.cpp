#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
 vector <long long> v;
 int counts=0,temp=0;
 while(scanf("%d",&temp)==1){
    v.push_back(temp);
    sort(v.begin(),v.end());
    if(counts%2==0)
        printf("%lld\n",v[counts/2]);
    else
        printf("%lld\n",(v[counts/2]+v[(counts+1)/2])/2);
    counts++;
 }
 return 0;
}
