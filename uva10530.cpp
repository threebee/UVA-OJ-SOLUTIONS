#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(){
    int num,low=0,high=11;
    string str;
    while(scanf("%d",&num),num){
        getchar();
        getline(cin,str);
        if(str=="right on"){
            if(low<num && num<high)
                printf("Stan may be honest\n");
            else
                printf("Stan is dishonest\n");
            low=0,high=11;
        }
        else{
            if(str=="too high"){
                if(num < high) high=num;
            }
            else{
                if(num > low) low=num;
            }
        }
    }
    return 0;
}
