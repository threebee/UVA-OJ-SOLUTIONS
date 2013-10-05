#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int gcd(int a,int b){
    while(b) {
        a=a%b;
        a^=b; b^=a; a^=b;
    }
    return a;
}

int main(){
    vector <int> v;
    int n,i,j,k,counts;
    while(scanf("%d",&n),n){
        k=sqrt(n);
        v.clear();
        counts=0;
        for(i=1;i<=k;i++){
            if(!(n%i)){
                v.push_back(i);
                if(i*i!=n)
                v.push_back(n/i);
            }
        }
        k=v.size();
        for(i=0;i<k;i++) for(j=i+1;j<k;j++)
            if(gcd(v[i],v[j])==1) counts++;
        printf("%d %d\n",n,counts+1);
    }
    return 0;
}
