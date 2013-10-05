#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    int t,n,m;
    char in;
    scanf("%d",&t);
    while(t--){
       cin>>in>>n>>m;
       if (in=='k')      printf("%d\n",(n*m+1)/2);
       else if (in=='K') printf("%d\n",((n+1)/2) * ((m+1)/2));
       else if (in=='Q') printf("%d\n",min(n,m));
       else              printf("%d\n",min(n,m));
    }
    return 0;
}
