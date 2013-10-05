#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main(){
 int a,b,c,d,e,i,j,n,t;
 scanf("%d",&t);
 int mat[25][25];
 while(t--){
    for(i=0;i<25;i++)
        for(j=0;j<25;j++)
          mat[i][j]=0;
    scanf("%d",&n);
    while(n--)
        scanf("%d %d %d",&i,&j,&d),mat[i][j]=d;
        int ans_a,ans_b,ans_c,ans_d,ans_e,mini=INT_MAX;
            for (int a = 0; a < 25; a++)
                for (int b = a + 1; b < 25; b++)
                    for (int c = b + 1; c < 25; c++)
                        for (int d = c + 1; d < 25; d++)
                            for (int e = d + 1; e < 25; e++) {
                                int sum = 0;
                                for (int row = 0; row < 5; row++)
                                    for (int col = 0; col < 5; col++) {
                                        int A = distance(row, col, a / 5, a % 5) * mat[row][col];
                                        int B = distance(row, col, b / 5, b % 5) * mat[row][col];
                                        int C = distance(row, col, c / 5, c % 5) * mat[row][col];
                                        int D = distance(row, col, d / 5, d % 5) * mat[row][col];
                                        int E = distance(row, col, e / 5, e % 5) * mat[row][col];
                                        sum += min(min(A,min(B, C)),min(D, E));
                                    }
                                if (sum < mini) {
                                    mini = sum;
                                    ans_a=a,ans_b=b,ans_c=c,ans_d=d,ans_e=e;
                                }
                            }

    printf("%d %d %d %d %d\n",ans_a,ans_b,ans_c,ans_d,ans_e);
 }
 return 0;
}
