#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n,cas=0;
    while(scanf("%d",&n) && n>=0)
        printf("Case %d: %.0lf\n",++cas,ceil(log(n)/log(2)));
    return 0;
}
