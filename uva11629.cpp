#include <cstdio>
#include <map>
#include <string>
#include <iostream>
using namespace std;

int main(){
 int n,m;
 map <string,float> mp;
 scanf("%d %d",&n,&m);
 bool flag;
 char input[1001];
 int b,c;
 while(n--){
    scanf("%s %d.%d",input,&b,&c);
    mp[input]=b*10+c;
 }
 string a;
 for(int i=1;i<=m;i++){
    flag=false;
    int total=0;
    while(cin>>a){
        if(a=="<"|| a==">" || a=="<=" || a==">=" || a=="=" ) break;
        total+=mp[a];
    }
    int k;
    cin>>k;
    k*=10;
    if(a=="<")      { if(!(total<k))  flag=true;   }
    else if(a==">") { if(!(total>k))  flag=true;   }
    else if(a=="<="){ if(!(total<=k)) flag=true;   }
    else if(a==">="){ if(!(total>=k)) flag=true;   }
    else            { if(!(total==k)) flag=true;   }

    if(flag) printf("Guess #%d was incorrect.\n",i);
    else     printf("Guess #%d was correct.\n",i);
 }

 return 0;
}
