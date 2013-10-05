#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

struct level {  int rise,space; };
typedef vector <level> vl;

int main(){
 int t,i,j,k,counts=0,maxi,mini;
 scanf("%d",&t);
 while(t--){
    char str[60];
    scanf("%s",str);
    printf("Case #%d:\n",++counts);
    k=50,maxi=0,mini=100;
    vector <vl> ans(110,vl());
    level s;
    for(i=0;i<strlen(str);i++){
        if(maxi<k+1) maxi=k+1;
        if(mini>k)   mini=k;
        if(str[i]=='R'){
            k++;
            s.rise=1; s.space=i;
            ans[k].push_back(s);
        }
        else if(str[i]=='F'){
            s.rise=-1; s.space=i;
            ans[k].push_back(s);
            k--;
        }
        else{
            s.rise=0; s.space=i;
            ans[k+1].push_back(s);
        }
    }
    for(i=maxi;i>=mini;i--){
        if((int)ans[i].size()==0) continue;
        printf("| ");
        for(k=0;k<(int)ans[i].size();k++){
            s=ans[i][k];
            if(k) {s.space=s.space-ans[i][k-1].space-1;}
            for(j=0;j<s.space;j++) printf(" ");
            if(s.rise==1)       printf("/");
            else if(s.rise==-1) printf("\\");
            else                printf("_");
        }
        if(i) printf("\n");
    }
    printf("+");
    for(i=0;i<=strlen(str)+1;i++) printf("-");
    printf("\n\n");
 }
 return 0;
}
