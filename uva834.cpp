#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int a,b;

    while(scanf("%d %d",&a,&b)==2){
        vector<int> c;
        do{
          if(a<b)
           c.push_back(0);
          else{

             c.push_back(a/b);
          }
          a=a%b;
          if(a==0) break;
          swap(a,b);
        }while(a!=1);
        if((c.size()-1)==0){
          printf("[%d]\n",c[c.size()-1]);
          continue;
        }

        printf("[%d;",c[0]);
        for(int i=1;i<c.size()-1;i++)
            printf("%d,",c[i]);
        printf("%d]\n",c[c.size()-1]);

    }

 return 0;
}
