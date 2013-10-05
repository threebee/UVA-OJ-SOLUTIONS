#include<cstdio>
#include<cstring>

char f[10000];
char factorial[1010][10000];

void multiply(int k){
    int carry,sum,i;
    int len = strlen(f);
    carry=0;
    i=0;
    while(i<len){
        sum=carry+(f[i] - '0') * k;
        f[i] = (sum % 10) + '0';
        i++;
        carry = sum/10;
    }
    while(carry>0){
        f[i++] = (carry%10) + '0';
        carry/=10;
    }
    f[i]='\0';
    for(int j=0;j<i;j++)
       factorial[k][j]=f[j];
    factorial[k][i]='\0';
}

int main(){
    int n;
    factorial[0][0]='1';
    factorial[1][0]='1';
    strcpy(f,"1");
    for(int k=2;k<=1000;k++) multiply(k);

    while(scanf("%d",&n)==1){
        print(n);
        int len = strlen(factorial[n]);
        printf("%d!\n",n);
        for(int i=len-1;i>=0;i--)  printf("%c",factorial[n][i]);
        printf("\n");
    }

    return 0;
}
