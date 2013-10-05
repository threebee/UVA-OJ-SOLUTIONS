#include <cstdio>
#define lli long long int

int main(){
 lli i,j;
 lli x=6,y=8;
 for(j=1;j<1000000000;j++){
    i=j+x+y;
    if((j*(j-1))/2 == ((i*(i+1))/2 - (j*(j+1))/2 )){
           printf("%lld  %lld\n",j,i);
           x=j; y=i;
    }
 }
 return 0;
}

/*
6 8
35  49
204  288
1189  1681
6930  9800
40391  57121
235416  332928
1372105  1940449
7997214  11309768
46611179  65918161
271669860  384199200
*/
