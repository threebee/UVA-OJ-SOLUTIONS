#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;


int main(){
  int cts=0;
  int t,i,j,n;
  char a;
  bool flag=true;
  char str[25][25];
  scanf("%d",&t);
  while(t--){
     scanf("%d",&n);
     for(i=0;i<n;i++) cin>>str[i];

     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(str[i][j]=='.'){
              a='A'; flag=true;
              while(flag){
                if(str[i-1][j]==a || str[i+1][j]==a || str[i][j-1]==a || str[i][j+1]==a) a++;
                else flag=false;
              }
              str[i][j]=a;
            }
        }
     }
     printf("Case %d:\n",++cts);
     for(i=0;i<n;i++){
         cout<<str[i]<<endl;
     }
  }
  return 0;
}
