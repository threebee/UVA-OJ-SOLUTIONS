#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int row[9],input[9][9],maxi;

bool place(int col,int tryrow){
    for(int prev=1;prev<col;prev++){
        if(row[prev]==tryrow || (abs(row[prev]-tryrow)==abs(prev-col)))
            return false;
    }
    return true;
}

void backtrack(int col){
    for(int tryrow=1;tryrow<=8; tryrow++){
        if(place(col,tryrow)){
            row[col]=tryrow;
            if(col == 8){
                int sum=0;
                for(int j=1;j<=8;j++) sum+=input[j][row[j]];
                maxi=max(maxi,sum);
            }
            else backtrack(col+1);
        }
    }
}

int main(){
 int k,i,j;
 scanf("%d",&k);
 while(k--){
    memset(row,0,sizeof row);
    memset(input,0,sizeof input);
    maxi=0;
    for(i=1;i<=8;i++) for(j=1;j<=8;j++)
      scanf("%d",&input[i][j]);
    backtrack(1);
    printf("%5d\n",maxi);
 }
 return 0;
}
