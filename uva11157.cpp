#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int main(){
 int t;
 scanf("%d",&t);
 for(int i=1;i<=t;i++){
    int n,length,maxi=0,temp,j;
    scanf("%d %d",&n,&length);
    vector <int> a;
    a.push_back(0);
    char c[20];
    for(j=0;j<n;j++){
        scanf("%s",c);
        sscanf(c+2,"%d",&temp);
        if(c[0]=='B'){
            a.push_back(temp);
            a.push_back(temp);
        }
        else{
            a.push_back(temp);
        }
    }
    a.push_back(length);
    if(a.size()==2)
        maxi=length;
    for(j=2;j<a.size();j+=2){
        if((a[j]-a[j-2])>maxi) maxi=a[j]-a[j-2];
    }
    for(j=3;j<a.size();j+=2){
        if((a[j]-a[j-2])>maxi) maxi=a[j]-a[j-2];
    }
    printf("Case %d: %d\n",i,maxi);
 }
 return 0;
}
