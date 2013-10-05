/*
  decision tree , tournament tree
  find largest and second largest
*/

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
    int n;
    while(scanf("%d",&n)==1){
        n--;
        printf("%d\n",n+(int)log2(n));
    }
    return 0;
}

