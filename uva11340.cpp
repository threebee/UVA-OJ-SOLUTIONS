#include <cstdio>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int atr[1000]={0};
        int n;
        scanf("%d",&n);
        while(n--)
        {
            unsigned char ch[2];
            int value;
            scanf("%s %d", ch , &value);
            atr[ch[0]+128]=value;
        }
        scanf("%d",&n);
        int res=0;
        char str[10002];
        gets(str);
        while(n--)
        {
            gets(str);
            for(int i =0;str[i];i++)
            {
                res=res+atr[str[i]+128];
            }
        }
        double r = res;
        r/=100;
        printf("%.2lf$\n",r);
    }
    return 0;
}
