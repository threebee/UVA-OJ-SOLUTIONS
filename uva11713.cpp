#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

bool isVowel(char ch){
    if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch =='u') return true;
    return false;
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        string str1,str2,f1(""),f2("");
        cin>>str1>>str2;
        if(str1.length()!=str2.length()) printf("No\n");
        else{
           for(int i=0;i<str1.length();i++)
            if(!isVowel(str1[i]))
              f1+=str1[i];

           for(int i=0;i<str2.length();i++)
            if(!isVowel(str2[i]))
              f2+=str2[i];

           if(f1==f2) printf("Yes\n");
           else       printf("No\n");
        }
    }
    return 0;
}
