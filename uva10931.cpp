#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

vector <int> v;

int main(){
 int n,i,parity,pos;
 while(scanf("%d",&n),n){
    v.clear();
    parity=0,pos=0;
    for(i=0;i<32;i++){
        if(n & (1<<i)){
            pos=i;
            parity++;
            v.push_back(1);
        }
        else  v.push_back(0);
    }
    printf("The parity of ");
    for(i=pos;i>=0;i--) printf("%d",v[i]);
    printf(" is %d (mod 2).\n",parity);
 }
 return 0;
}
