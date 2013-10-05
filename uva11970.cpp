#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    long long int n,t,i,len,x,j;
    vector<int>output;
    scanf("%lld",&t);

    len = sqrt(1000000000);
    for(j=1;j<=t;j++){
        output.clear();
        scanf("%lld",&n);
        for(i=1;i<=len;i++){
            x = n-i*i;
            if(x%i==0&&x>0)output.push_back(x);
        }
        sort(output.begin(),output.end());
        printf("Case %lld:",j);
        for(i=0;i<output.size();i++) printf(" %lld",output[i]);
        printf("\n");
    }
    return 0;
}
