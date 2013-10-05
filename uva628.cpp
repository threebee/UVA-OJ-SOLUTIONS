#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

char str[105][105],rule[1010][105];
int counter[8];

int mpow(int i,int counts){
    int val=1;
    for(int j=0;j<counts;j++) val*=i;
    return val;
}

void array_clear(){ memset(counter,0,sizeof counter); }

void array_adder(int len){
    int c=0,i=1;

    if(counter[0]+1 > 9) c=1,counter[0]=0;
    else                 counter[0]+=1,c=0;

    while(i<len){
        if((counter[i]+c) > 9)
            c=1,counter[i]=0;
        else counter[i]+=c,c=0;
        i++;
    }
}

int array_counter(int id,int len){ return counter[len-id-1]; }


int main(){
   //freopen("out.txt","w",stdout);
   int S,R,count_str,count_rule,num_str,num_rule;
   while(scanf("%d",&S)==1){

        for(int i=0;i<S;i++) cin>>str[i];

        scanf("%d",&R);
        for(int i=0;i<R;i++) cin>>rule[i];
        printf("--\n");
      //  cout<<"R:"<<R<<endl;
        for(int i=0;i<R;i++){
            int counts=0;
            for(int j=0;j<strlen(rule[i]);j++){
                if(rule[i][j]=='0') counts++;
            }
            if(counts==strlen(rule[i])){
                  int val=0;
                  array_clear();
                  int limit=mpow(10,counts);
              //    cout<<"limit:"<<limit<<endl;
                  while(val<limit){
                    int pos=0;
                    for(int j=0;j<strlen(rule[i]);j++){
                        cout<<array_counter(pos,counts);
                        pos++;
                      }
                    cout<<endl;
                    array_adder(counts);
                    val++;
                  }
            }
            else if(counts){
                int val;
                //cout<<"counts:"<<counts<<endl;
                for(int t=0;t<S;t++){
                  val=0;
                  array_clear();
                  int limit=mpow(10,counts);
              //    cout<<"limit:"<<limit<<endl;
                  while(val<limit){
                    int pos=0;
                    for(int j=0;j<strlen(rule[i]);j++){
                      if(rule[i][j]=='#') cout<<str[t];
                      else{
                        cout<<array_counter(pos,counts);
                        pos++;
                      }
                    }
                    cout<<endl;
                    array_adder(counts);
                    val++;
                   }
                }
            }
            else{
                for(int j=0;j<S;j++){
                    for(int k=0;k<strlen(rule[i]);k++)
                        cout<<str[j];
                    cout<<endl;
                }
            }

        }
   }
   return 0;
}
