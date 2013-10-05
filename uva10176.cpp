#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define MOD 131071

int power[10010];
char input[110],final_input[10010];

int main(){
   int i,n;
   power[0]=1;
   for(i=1;i<=10004;i++) power[i]=(2*power[i-1])%MOD;

   while(scanf("%s",input)!=EOF){
        if(input[strlen(input)-1]!='#'){
            strcpy(final_input,input);
            while(scanf("%s",input) && input[strlen(input)-1]!='#')
                strcat(final_input,input);
            strcat(final_input,input);
        }
        else  strcpy(final_input,input);
        int sum=0,j=0;
        for(i=strlen(final_input)-2;i>=0;i--){
            sum=(sum + (final_input[i]-'0')*power[j++] )%MOD;
        }

        if(sum==0) printf("YES\n");
        else       printf("NO\n");
   }
   return 0;
}
