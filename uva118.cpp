#include <cstdio>
#include <cstring>
using namespace std;

int main(){
   int m,n;
   scanf("%d %d",&m,&n);
   int a[m][n];
   bool lost;
   char pos,s[110];
   int s1,s2;
   memset(a,1,sizeof(a));
   while(scanf("%d %d %c %s",&s1,&s2,&pos,s)!=EOF){
      lost=false;
      for(int i=0;i<strlen(s);i++){
        if(s[i]=='F'){
            if(pos=='N'){
                if(a[s1][s2] || !(s2+1>n)){
                    s2+=1;
                    if(s2>n || s2<0){ lost=true,a[s1][s2-1]=0,s2-=1; break;}
                }
            }
            else if(pos=='E'){
                if(a[s1][s2] || !(s1+1>n)){
                    s1+=1;
                    if(s1>m || s1<0){ lost=true,a[s1-1][s2]=0,s1-=1; break;}
                }
            }
            else if(pos=='W'){
                if(a[s1][s2] || !(s1-1<0)){
                    s1-=1;
                    if(s1>m || s1<0){ lost=true,a[s1+1][s2]=0,s1+=1; break;}
                }
            }
            else{
                if(a[s1][s2] || !(s2-1<0)){
                    s2-=1;
                    if(s2>n || s2<0) {lost=true,a[s1][s2+1]=0,s2+=1; break;}
                }

            }
        }
        else if(s[i]=='L'){
            if(pos=='N')      pos='W';
            else if(pos=='E') pos='N';
            else if(pos=='W') pos='S';
            else              pos='E';
        }
        else{
            if(pos=='N')      pos='E';
            else if(pos=='E') pos='S';
            else if(pos=='W') pos='N';
            else              pos='W';
        }
        // printf("// %d %d %c\n",s1,s2,pos);

      }
      printf("%d %d %c",s1,s2,pos);
      if(lost) printf(" LOST");
      printf("\n");
   }
   return 0;
}
