#include <iostream>
using namespace std;

int main(){
 cout<<"The 1500'th ugly number is 859963392.\n";
 return 0;
}

/*
#include <iostream>
using namespace std;

typedef long long int lli;

int main(){
 lli a,b,c,temp;
 int counts=0;
 for(lli i=1;;i++ ){
    temp=i;
    if(temp%2==0)
        while(temp%2==0) temp/=2;
    if(temp%3==0)
        while(temp%3==0) temp/=3;
    if(temp%5==0)
        while(temp%5==0) temp/=5;
    if(temp==1)
        counts++,cout<<i<<endl;
    if(counts==1500){
        cout<<i;
        break;
    }
 }

 return 0;
}
*/
