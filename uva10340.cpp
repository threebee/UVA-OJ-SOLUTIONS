#include <cstdio>
#include <cstring>

int main(){
    char s[1000000],t[1000000];
    int i,j,len1,len2;
    bool flag;
    while(scanf("%s %s",s,t)==2){
        flag=false;
        len1=strlen(t); len2=strlen(s);
        j=0;
        for(i=0;i<len1;i++){
            if(s[j]==t[i]){
                j++;
                if(j==len2){
                    flag=true;
                    break;
                }
            }
        }
        if(flag) printf("Yes\n");
        else     printf("No\n");
    }
    return 0;
}
