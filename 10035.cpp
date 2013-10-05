#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long unsigned x, y;
    while(scanf("%llu %llu", &x, &y)==2){
          if(x==0 && y==0) break;
          int count= 0, carry=0;

          while(x>0 || y>0){
            carry= x%10 + y%10 + carry;
            if(carry>=10) count++;
            carry= carry/10;
            x/=10;
            y/=10;
          }

        if(count==0) cout << "No carry operation."<< endl;
        else if(count==1) cout << "1 carry operation." << endl;
        else cout << count << " carry operations." << endl;
    }
    return 0;
}
