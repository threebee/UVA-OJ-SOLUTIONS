/* http://www.mathpages.com/home/kmath107.htm

Partitions into Consecutive Integers

For any positive integer N, let f(N) denote the number of ways in
which n can be expressed as the sum of consecutive positive integers.
For example, since 9 can be expressed as 2+3+4 and as 4+5 and as 9,
we have f(9)=3.

The sum of the integers from 1 to n is n(n+1)/2, so we're looking
for the number of ways in which a given integer N can be expressed
in the form
                  N = n(n+1)/2 - m(m+1)/2                   (1)

for a positive integer n and non-negative integer m.  Solving this
for m gives
                        ____________________
                  -1 + / 1 - 4[2N - n(n+1)]
          m   =   ---------------------------
                                2

which implies that the quantity inside the square root must be a
square integer.  Thus there is an integer u such that

           4n^2 + 4n + 1 - 8N - u^2  =  0

Clearly u must be odd.  Solving this for n gives
                             _________
                       -1 + / 8N + u^2
                n  =   ----------------
                                2

Again, this requires that the quantity inside the square root is a
square integer, so we have an integer v such that

            8N  =  v^2 - u^2  =  (v-u)(v+u)

and since u is odd, v must also be odd.  Thus we can write this in
the form
               2N  =  [(v-u)/2] [(v+u)/2]

So we are looking for ways of factoring 2N into two factors, A=(v-u)/2
and B=(v+u)/2 with odd integers u,v.  We have v=A+B and u=B-A, so A
and B must have opposite parity, i.e., one is odd and one is even.
Thus, the integers A,B give a solution if and only if 2N = AB and one
of A,B is odd and the other is even.  Clearly this occurs for any odd
divisor d of N, which let's us take A=d and B=2N/d (or vice versa,
which ever give B > A).  Consequently, the number of ways of expressing
N as a sum of consecutive positive integers is equal to the number of
odd divisors of N.

For example, there are three odd divisors of N=9, namely 1, 3, and 9,
so we have f(9) = 3, corresponding to the three solutions

          A   B     v   u     n   m       expression
         --- ---   --- ---   --- ---     -------------
          1   18    19  17     9  8        9
          3    6     9   3     4  1        2+3+4
          2    9    11   7     5  3        4+5

Incidentally, if we let F(N) denote the number of ways of expressing
N  as the sum of consecutive integers, without requiring that they be
positive integers, then clearly F(N) = 2f(N), because for any sum of
consecutive integers extending from -m to n the total is again given
by equation (1), and for each solution that ranges from m+1 to n
there corresponds an equivalent solution ranging from -m to n.

Return to MathPages Main Menu
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef vector<int> vi;

int main(){
   //freopen("out.txt","w",stdout);
   vector <lli> div;
   lli s,i;
   while(scanf("%lld",&s)){
       if(s<0) break;
       div.clear();
       lli limit=sqrt(s);
       for(i=1;i<=limit;i++) if(s%i == 0){
            if(i%2) div.push_back(i);
            if(i!=s/i && (s/i)%2) div.push_back(s/i);
       }
       lli n,m,a,b,v,u,diff=0,f_n,f_m;
       for(i=0;i<div.size();i++){
          a=div[i]; b=(2*s)/a;
          if(a>b) swap(a,b);
          v=a+b; u=b-a;
          n=((int)sqrt(8*s + u*u) - 1)/2;
          m=((int)sqrt(1 + 4*n*(n+1) - 8*s ) - 1)/2;
          if((n-m) > diff){
            diff=abs(n-m);
            f_n=n,f_m=m;
          }
       }
       printf("%lld = %lld + ... + %lld\n",s,f_m+1,f_n);
   }
   return 0;
}
