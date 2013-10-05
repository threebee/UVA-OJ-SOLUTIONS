#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;

int main(){
    int t;
    string str;
    scanf("%d",&t);
    getchar();
    while(t--){
        getline(cin,str);
        bool flag=true;
        stack <char> s;
        for(int i=0;i<str.length();i++){
            if(str[i]=='(' || str[i]=='[') s.push(str[i]);
            else{
                if(str[i]==']'){
                    if(s.empty()){
                        flag=false;
                        break;
                    }
                    char ch=s.top();
                    if(ch=='[') s.pop();
                    else{
                      flag=false;
                      break;
                    }
                }
                else{
                    if(s.empty()){
                        flag=false;
                        break;
                    }
                    char ch=s.top();
                    if(ch=='(') s.pop();
                    else{
                      flag=false;
                      break;
                    }
                }

            }
        }
        if(!s.empty()) flag=false;
        if(flag) printf("Yes\n");
        else     printf("No\n");
    }
    return 0;
}
