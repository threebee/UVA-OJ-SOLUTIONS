/* do not print newline
   after last testcase
*/

#include <cstdio>
#include <cstring>
using namespace std;

int row[17],n;
bool v[20];

bool isprime(int num){
    if(num < 2) return false;
    if(num == 2) return true;
    if(num % 2 == 0) return false;
    for(int i=3; (i*i)<=num; i+=2){
        if(num%i == 0 ) return false;
    }
    return true;
}


void backtrack(int val){
    for(int trynum=2;trynum<=n;trynum++){
        if(isprime(row[val-1]+trynum) && !v[trynum]){
            row[val]=trynum;
            v[trynum]=1;
            if(val==n && isprime(row[n]+row[1])){
               for(int i=1;i<=n-1;i++) printf("%d ",row[i]);
                printf("%d\n",row[n]);
            }
            else backtrack(val+1);
            v[trynum]=0;
        }
    }
}

int main(){
 int i,j,cas=0;
 //freopen("out.txt","w",stdout);
 while(scanf("%d",&n)==1){
    ++cas;
    if(cas==1)  printf("Case %d:\n",cas);
    else printf("\nCase %d:\n",cas);
    if(n==1){
        printf("1\n"); continue;
    }
    memset(v,false,sizeof v);
    memset(row,0,sizeof row);
    v[1]=1;
    row[1]=1;
    backtrack(2);
    //printf("\n");
 }
 return 0;
}
