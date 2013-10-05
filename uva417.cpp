#include<cstdio>
#include<map>
#include<string>
#include<algorithm>
using namespace std;

int  main()
{
    map <string,int> mapper;

    int i,j,k,l,m,idx=0;

    for(i='a';i<='z';i++)
    {
      char s[]={i,'\0'};
      mapper[s]=++idx;
    }

        for(i='a';i<='z';i++)
        for(j=i+1;j<='z';j++)
            {
               char s[]={i,j,'\0'};
               mapper[s]=++idx;
            }

      for(i='a';i<='z';i++)
      for(j=i+1;j<='z';j++)
      for(k=j+1;k<='z';k++)
      {
        char s[]={i,j,k,'\0'};
        mapper[s]=++idx;
      }

        for(i='a';i<='z';i++)
        for(j=i+1;j<='z';j++)
        for(k=j+1;k<='z';k++)
        for(l=k+1;l<='z';l++)
        {
            char s[]={i,j,k,l,'\0'};
            mapper[s]=++idx;
        }


        for(i='a';i<='z';i++)
        for(j=i+1;j<='z';j++)
        for(k=j+1;k<='z';k++)
        for(l=k+1;l<='z';l++)
        for(m=l+1;m<='z';m++)
        {
            char s[]={i,j,k,l,m,'\0'};
            mapper[s]=++idx;
        }
        char a[10];
        while(scanf("%s",a))
        {
            if(mapper.find(a)!=mapper.end()) printf("%d\n",mapper[a]);
            else  printf("0\n");
        }

    return 0;
}
