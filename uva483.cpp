#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string a;
  char b;
  while(cin>>a){
    b=getchar();
    reverse(a.begin(),a.end());
    cout<<a;
    putchar(b);
  }
  return 0;
}
