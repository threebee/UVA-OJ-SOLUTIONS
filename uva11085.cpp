#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

int row[9],input[9],mini;

bool place(int trynow,int col){
    for(int prev=1;prev<col;prev++){
        if(row[prev]==trynow || (abs(row[prev]-trynow)==abs(prev-col)))
            return false;
        }
    return true;
}

void backtrack(int col){
    for(int trynow=1;trynow<=8;trynow++){
        if(place(trynow,col)){
            row[col]=trynow;
            if(col==8){
                int sum=0;
                for(int i=1;i<=8;i++)
                    if(input[i]!=row[i]) sum++;
                mini=min(mini,sum);
            }
            else backtrack(col+1);
        }
    }
}

int main(){
    int cas=0;
    while(scanf("%d",&input[1])==1){
       for(int i=2;i<=8;i++) scanf("%d",&input[i]);
       memset(row,0,sizeof row);
       mini=INT_MAX;
       backtrack(1);
       printf("Case %d: %d\n",++cas,mini);
    }
    return 0;
}
