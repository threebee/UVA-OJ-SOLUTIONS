#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
 char str[60];
 int t,i,counts,counts1,counts2,pos,pos1,pos2,x,y,z;
 bool flag=false;
 scanf("%d",&t);
 while(t--){
    scanf("%s",str);
    flag=false;
    counts=counts1=counts2=pos1=pos2=x=y=z=0;
    if(str[0]!='?') {printf("no-theorem\n"); continue;}
    for(i=0;i<strlen(str);i++){
     if(str[i]=='?' || str[i]=='M' || str[i]=='E'){
            if(str[i]=='M') counts1++,pos1=i;
            if(str[i]=='E') counts2++,pos2=i;
            counts++;
            if(!pos1) x++;
            else if(pos1 && !pos2) y++;
            else z++;
     }
     else {
        flag=true;
        break;
     }
    }
    if(counts1>1 || counts2>1) flag=true;

    if(pos1>=pos2) flag=true;

    if(z!=(x+y)) flag=true;

    if(counts==strlen(str)){
        if(strchr(str,'M')){
            pos=int(strchr(str,'M')-str);
            if(str[pos-1]!='?' || str[pos+1]!='?') flag=true;
        }
        else flag=true;

        if(strchr(str,'E')){
            pos=int(strchr(str,'E')-str);
            if(str[pos-1]!='?' || str[pos+1]!='?') flag=true;
        }
        else flag=true;
    }
    else flag=true;

    if(flag) printf("no-theorem\n");
    else     printf("theorem\n");
 }
 return 0;
}
