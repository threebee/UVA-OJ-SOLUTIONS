#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
using namespace std;

int main(){
    int t;
    string str;
    while(scanf("%d",&t),t){
        int top = 1,down = 6,east = 4,west = 3,north = 2,south = 5,temp;
        while(t--){
            cin>>str;
            if(str=="north"){
                temp = north;
                north = top;
                top = south;
                south = down;
                down = temp;
            }
            else if(str=="east"){
                temp = top;
                top = west;
                west = down;
                down = east;
                east = temp;
            }
            else if(str=="west"){
                temp = top;
                top = east;
                east = down;
                down = west;
                west = temp;
            }
            else{
                temp = top;
                top = north;
                north = down;
                down = south;
                south = temp;
            }
        }
        printf("%d\n",top);
    }
    return 0;
}
