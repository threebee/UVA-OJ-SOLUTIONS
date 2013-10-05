#include <cstdio>
#include <cmath>
#include <climits>

int main(){
    int cases,n,m,k,i,j;
    scanf("%d",&cases);
    for(i=1;i<cases+1;i++){
        scanf("%d %d %d",&n,&m,&k);
        long sum=0;
        int cakes[m];
        for(j=0;j<m;j++){
            scanf("%d",&cakes[j]);
            sum+=cakes[j];
        }
        int drinks[k];
        for(j=0;j<k;j++){
            scanf("%d",&drinks[j]);
            sum+=drinks[j];
        }
        int temp;
        for(j=k+m;j<n;j++){
            scanf("%d",&temp);
            sum+=temp;
        }

        double min=INT_MAX,avg=(double)sum/n;
        int index=-1;
        for(j=0;j<m;j++){
            if(min>fabs(cakes[j]-avg)){
                min=fabs(cakes[j]-avg);
                index=j;
            }else if(min==fabs(cakes[j]-avg)){
                if(cakes[j]<cakes[index])
                     index=j;
            }
        }
        printf("Case #%d:",i);
        printf(" %d",cakes[index]);
        min=INT_MAX;
        int indexD=-1;
        for(j=0;j<k;j++){
            if(min>fabs(drinks[j]-avg)){
                min=fabs(drinks[j]-avg);
                indexD=j;
            }else if(min==fabs(drinks[j]-avg)){
                if(drinks[j]<drinks[index])
                     index=j;
            }
        }
        printf(" %d\n",drinks[indexD]);
    }
    return 0;
}
