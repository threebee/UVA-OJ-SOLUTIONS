#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

int main(){
 char a[1015],b[1015];
 int ans1[26],ans2[26];
 int i,j;
 while(gets(a)){
    gets(b);
    for(i=0;i<26;i++) ans1[i]=ans2[i]=0;
    for(i=0;i<strlen(a);i++) ans1[a[i]-'a']++;
    for(i=0;i<strlen(b);i++) ans2[b[i]-'a']++;
    for(i=0;i<26;i++){
        ans1[i]=min(ans1[i],ans2[i]);
        while(ans1[i]--) cout<<(char)('a'+i);
    }
    cout<<endl;
 }
 return 0;
}
