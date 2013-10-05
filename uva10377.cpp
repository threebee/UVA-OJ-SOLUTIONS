#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;

int main(){
    int t,n,m,in_i,in_j,ct;
    char input[65][65],ch,direc,op[100000];
    int mat[65][65];
    bool flag=false;

    map <char,char> right,left;
    left['N']='W'; left['W']='S'; left['S']='E'; left['E']='N';
	right['N']='E'; right['E']='S'; right['S']='W'; right['W']='N';

    map <char,int> x,y;
    x['N']=0 ; x['S']=0 ; x['E']=1 ; x['W']=-1;
    y['N']=-1 ; y['S']=1 ; y['E']=0 ; y['W']=0;

    scanf("%d",&t);
    while(t--){
        scanf("%d %d\n",&n,&m);
        memset(mat,0,sizeof mat);

        for(int i=0; i<n; i++)  gets(input[i]);

        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
             if (input[i][j] == ' ') mat[i+1][j+1] = 0;
             else if (input[i][j] == '*') mat[i+1][j+1] = 1;

        cin>>in_i>>in_j;

        direc='N'; ct=0;

        while((ch=getchar())!=EOF){
            if(ch=='Q'){
               op[ct++]='\0';
               break;
            }
            else if(ch=='R'){
                op[ct++]='R'; continue;
            }
            else if(ch=='L'){
                op[ct++]='L';
                continue;
            }
            else if(ch=='F'){
                op[ct++]='F';
            }
            else continue;
        }

        for(int i=0;i<strlen(op);i++){
            if(op[i]=='R'){
                direc=right[direc];
                continue;
            }
            else if(op[i]=='L'){
                direc=left[direc];
                continue;
            }
            else if(op[i]!='F') continue;

            if(mat[in_i+y[direc]][in_j+x[direc]]) continue;

            in_i+=(y[direc]);
            in_j+=(x[direc]);
        }
        if(flag) printf("\n"); flag=true;
        printf("%d %d %c\n",in_i,in_j,direc);
    }
    return 0;
}
