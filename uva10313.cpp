#include <cstdio>
#include <cstring>
#include <cstdlib>

long long int val(int sum,int l){
    long long int st[310];
    memset(st,0,sizeof(st));
    st[0]=1;
    for(int i=1;i<=l;i++)
        for(int j=i;j<=sum;j++)
          st[j]+=st[j-i];
    return st[sum];
}

int main(){
    char str[20],*pch;
    int a[3],counts=0;
    long long int ans[310];
    memset(ans,0,sizeof(ans));
    ans[0]=1;
    for(int i=1;i<=305;i++)
        for(int j=i;j<=305;j++)
            ans[j]+=ans[j-i];
    while(gets(str)){
        counts=0;
        for(pch=strtok(str," ");pch;pch=strtok(NULL," ")) { a[counts++]=atoi(pch); }
        if(counts==1)       { printf("%lld\n",ans[a[0]]); }
        else if(counts==2)  { printf("%lld\n",val(a[0],a[1])); }
        else {
           if(a[0]==0) printf("1\n");
           else        printf("%lld\n",val(a[0],a[2])-val(a[0],a[1]-1));
        }
    }
    return 0;
}
