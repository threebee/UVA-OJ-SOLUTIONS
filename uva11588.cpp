#include <cstdio>
#include <cstring>

int main(){
 int t,a[26];
 scanf("%d",&t);
 for(int k=1;k<=t;k++){
    memset(a,0,sizeof(a));
    int r,c,m,n;
    char temp[22];
    scanf("%d %d %d %d",&r,&c,&m,&n);
    for(int i=0;i<r;i++){
        scanf("%s",temp);
        for(int p=0;p<strlen(temp);p++)
            a[temp[p]-'A']++;
    }

    int maxi=0,total=0;
    for(int i=0;i<26;i++) if(a[i]>maxi) maxi=a[i];

    for(int i=0;i<26;i++)
    total+=(a[i]==maxi)?(maxi*m):(a[i]*n);

    printf("Case %d: %d\n",k,total);
 }
 return 0;
}
