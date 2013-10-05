#include  <cstdio>
#include  <cmath>
#include  <iostream>
using namespace std;

int main(){
 int n;
 while(scanf("%d",&n)){
    if(n==0) break;
    double a[n+1],total=0;
    int i;
    for(i=0;i<n;i++){
        scanf("%lf",&a[i]);
        total+=a[i];
    }
    total=total/n;
    total=long(total*100 + 0.5)/100.0;

    double money_more=0,money_less=0;
    for(i=0;i<n;i++){
        if(a[i]>total) money_more+=(a[i]-total);
        else           money_less+=(total-a[i]);
    }
    printf("$%0.2lf\n",min(money_less,money_more));
 }

 return 0;
}


/*
problem with rounding function (why?)
3
10.00
20.00
30.00
4
15.00
15.01
3.00
3.01
3
6.17
5.00
4.03
12
123.12
6.13
9.44
89.08
278.78
223.78
78.45
912.89
554.76
547.57
1781.89
907.07
2
4.99
15.00
1
10.00
15
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.01
0.03
5
5000.00
11.11
11.11
11.11
11.11
15
0.01
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
0.03
4
25.00
25.00
25.00
28.00
3
10.01
15.25
18.96
4
25.03
25.00
25.00
25.00
0

correct output:
$10.00
$11.99
$1.10
$2407.09
$5.00
$0.00
$0.01
$3991.11
$0.01
$2.25
$4.73
$0.02
*/
