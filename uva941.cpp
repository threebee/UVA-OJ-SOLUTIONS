#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define lli long long int

string str;
lli id,;
lli fac[]={1,2,6,24,120,720,5040,40320,362880,3628800,39916800,479001600,6227020800,87178291200,1307674368000,20922789888000,355687428096000,6402373705728000,121645100408832000};

void print_ans(){
    sort(str.begin(),str.end());
    int l=str.length();
    lli temp;
    if(id==0){
        cout<<str;
        return;
    }
    if(!id%fac[l-1-1]){
        temp=id/fac[l-1-1];
        temp=-1;
        printf("%c",str[temp]);
        id-=fac[l-1-1]*temp;
        str.erase(str.begin()+temp);
        print_ans();
    }
    else{
        temp=id/fac[l-1-1];
        printf("%c",str[temp]);
        id-=fac[l-1-1]*temp;
        str.erase(str.begin()+temp);
        print_ans();
    }
}



int main(){
  int t;
  scanf("%d",&t);
  while(t--){
   cin>>str;
   scanf("%lld",&id);
   print_ans();
   printf("\n");
  }
 return 0;
}
