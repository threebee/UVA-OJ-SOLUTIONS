#include <cstdio>
#include <vector>
#include <string>
using namespace std;

int main(){
    vector<string> c;
    c.push_back("BCG");
    c.push_back("BGC");
    c.push_back("CBG");
    c.push_back("CGB");
    c.push_back("GBC");
    c.push_back("GCB");
    int b1,b2,b3,b4,b5,b6,b7,b8,b9;
    while(scanf("%d %d %d %d %d %d %d %d %d",&b1,&b2,&b3,&b4,&b5,&b6,&b7,&b8,&b9)!=EOF){
        int a[6];
        a[0]=b2+b3+b4+b5+b7+b9;
        a[1]=b2+b3+b4+b6+b7+b8;
        a[2]=b1+b2+b5+b6+b7+b9;
        a[3]=b1+b2+b4+b6+b8+b9;
        a[4]=b1+b3+b5+b6+b7+b8;
        a[5]=b1+b3+b4+b5+b8+b9;
        int mini=a[0],min_id=0;
        for(int i=0;i<6;i++)
            if(mini>a[i])
               mini=a[i],min_id=i;
        printf("%s %d\n",c[min_id].c_str(),a[min_id]);
    }
    return 0;
}
