#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define LL long long int

struct player{
    string name;
    LL time;
}s[110];

bool cmp(player a,player b){
    if(a.time==b.time){
        transform(a.name.begin(),a.name.end(),a.name.begin(),::tolower);
        transform(b.name.begin(),b.name.end(),b.name.begin(),::tolower);
        return a.name<b.name;
    }
    return a.time<b.time;
}

int main(){
 int t,i,t1,t2,t3,h,m,row=0;
 char gr1[3],gr2[4],gr3[4],gr4[4],name[100];
 while(scanf("%d",&t)==1){
    row=0;
    for(i=0;i<t;i++){
        scanf("%s %s %d %s %d %s %d %s",name,gr1,&t1,gr2,&t2,gr3,&t3,gr4);
        s[i].name=name;
        s[i].time=(LL)(t1*60*1000LL+t2*1000LL+t3);
    }
    sort(s,s+t,cmp);
    for(i=0;i<t;i+=2){
        if(i%2==0) row++;
        printf("Row %d\n",row);
        if(i<t) printf("%s\n",s[i].name.c_str());
        if(i+1<t) printf("%s\n",s[i+1].name.c_str());
    }
    printf("\n");
 }
 return 0;
}
