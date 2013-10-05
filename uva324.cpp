#include<cstdio>
#include<cstring>

char f[10000];
char factorial[1010][10000];
int counts[10];

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

    while(scanf("%d",&n),n){
        memset(counts,0,sizeof counts);
        int len = strlen(factorial[n]);
        printf("%d! --\n",n);
        for(int i=len-1;i>=0;i--) counts[factorial[n][i]-'0']++;
        printf("   (%d)%5d",0,counts[0]);
        printf("   (%d)%5d",1,counts[1]);
        printf("   (%d)%5d",2,counts[2]);
        printf("   (%d)%5d",3,counts[3]);
        printf("   (%d)%5d",4,counts[4]);
        printf("\n");
        printf("   (%d)%5d",5,counts[5]);
        printf("   (%d)%5d",6,counts[6]);
        printf("   (%d)%5d",7,counts[7]);
        printf("   (%d)%5d",8,counts[8]);
        printf("   (%d)%5d",9,counts[9]);
        printf("\n");
    }

    return 0;
}

