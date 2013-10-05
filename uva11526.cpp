#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      long long n;
      cin>>n;
      if(n<1){
        printf ("0\n");
        continue;
      }
      long long length = (long long) sqrt (n);
      long long lastQuo;
      long long prevQuo = n;
      long long sum = 0;
      int i;
      for(i=1;i<=length;i++){
        lastQuo=n/i;
        sum+=lastQuo;
        sum+=(prevQuo-lastQuo)*(i-1);
        prevQuo=lastQuo;
      }
      if(prevQuo>length) sum+=length;
      cout<<sum<<endl;
    }
    return 0;
}
