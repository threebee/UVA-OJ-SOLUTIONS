#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

int main()
{
    int a[3001],b[3001],i,n,flag;
    while(scanf("%d",&n)!=EOF)
    {
        flag=0;
        memset(b,0,sizeof(b));
        for(i=0;i<n;i++) scanf("%d",&a[i]);

        for(i=0;i<n-1;i++) b[labs(a[i]-a[i+1])]++;

        for(i=1;i<n;i++)
        if(b[i]==0){ flag=1; break; }

        if(flag) printf("Not jolly\n");
        else printf("Jolly\n");
    }

    return 0;
}
