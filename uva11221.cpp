#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int pq[101]={0,1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,
             289,324,361,400,441,484,529,576,625,676,729,784,841,900,
             961,1024,1089,1156,1225,1296,1369,1444,1521,1600,1681,1764,
             1849,1936,2025,2116,2209,2304,2401,2500,2601,2704,2809,2916,
             3025,3136,3249,3364,3481,3600,3721,3844,3969,4096,4225,4356,
             4489,4624,4761,4900,5041,5184,5329,5476,5625,5776,5929,6084,
             6241,6400,6561,6724,6889,7056,7225,7396,7569,7744,7921,8100,
             8281,8464,8649,8836,9025,9216,9409,9604,9801,10000};


int main(){
    char input[100000],*pch;
    int t,cnt=0,i,j,n,len;
    scanf("%d",&t);
    getchar();
    while(t--){
        gets(input);
        string final="";
        for( pch=strtok(input," (),.!?"); pch ; pch=strtok(NULL," (),.!?") ) final+=pch;
        if(!binary_search(pq,pq+101,(int)final.length())){
                printf("Case #%d:\n",++cnt);
                printf("No magic :(\n");
                continue;
        }
        string final_r=final,final_s="",final_t="";
        reverse(final_r.begin(),final_r.end());
        len=(int)final.length();
        n=(int)sqrt(len);

        for(j=0;j<n;j++)
            for(i=0;i<n;i++){
                final_s+=final[i*n+j];
                final_t+=final_r[i*n+j];
            }
        if(final==final_r && final==final_s && final==final_t){
            printf("Case #%d:\n",++cnt);
            printf("%d\n",n);
        }
        else{
             printf("Case #%d:\n",++cnt);
             printf("No magic :(\n");
        }
    }
    return 0;
}
