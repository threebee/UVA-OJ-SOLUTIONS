//submission error

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

string P;
bool palindrome(int a,int b){
    while(a<b){
        if(P[a]!=P[b-1]) return false;
        a++; b--;
    }
    return true;
}

bool allindrome(){
    int l=P.length();
    for(int i=0;i<l-1;i++){
        if(palindrome(0,i+1) && palindrome(i+1,l))
            return true;
    }
    return false;
}

int main(){
  int t;
  cin>>t;
  while(t--){
    cin>>P;
    if(allindrome())                  cout<<"alindrome\n";
    else if(palindrome(0,P.length())) cout<<"palindrome\n";
    else                              cout<<"simple\n";
  }
 return 0;
}
