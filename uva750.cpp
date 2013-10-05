#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int row[9],a,b,line;

bool place(int trynow,int col){
    for(int prev=1;prev<col;prev++)
       if(row[prev]==trynow || (abs(row[prev]-trynow)==abs(col-prev)))
        return false;
    return true;
}

void backtrack(int val){
    for(int trynow=1;trynow<9;trynow++){
        if(place(trynow,val)){
            row[val]=trynow;
            if(val==8 && row[b]==a){
                printf("%2d      %d",++line,row[1]);
                for (int j=2;j<=8;j++) printf(" %d", row[j]);
                printf("\n");
            }
            else backtrack(val+1);
        }
    }
}



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
      scanf("%d %d",&a,&b);
      memset(row, 0,sizeof row); line=0;
      printf("SOLN       COLUMN\n");
      printf(" #      1 2 3 4 5 6 7 8\n\n");
      backtrack(1);
      if(t) printf("\n");
    }
    return 0;
}
