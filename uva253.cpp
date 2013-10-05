#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string side(char a,char b){
    if(a<b) return a+""+b;
    return b+""+a;
}

int main(){
   char input[20];
   vector <string> vs1,vs2;
   bool flag;
   while(gets(input)){
        vs1.clear(); vs2.clear();

        vs1.push_back(side(input[0],input[5]));
        vs1.push_back(side(input[1],input[4]));
        vs1.push_back(side(input[2],input[3]));
        vs2.push_back(side(input[6],input[11]));
        vs2.push_back(side(input[7],input[10]));
        vs2.push_back(side(input[8],input[9]));

        sort(vs1.begin(),vs1.end());
        sort(vs2.begin(),vs2.end());
        flag=true;
        for(int i=0;i<3;i++)
            if(vs1[i]!=vs2[i]){
                flag=false;
                break;
            }
        if(flag) printf("TRUE\n");
        else     printf("FALSE\n");
   }
   return 0;
}

