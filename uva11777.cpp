#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int t,cas=0;
    int t1,t2,f1,att,ct[3];
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d %d %d %d %d",&t1,&t2,&f1,&att,&ct[0],&ct[1],&ct[2]);
        int sum=0;
        sum=t1+t2+f1+att;
        sort(ct,ct+3);
        sum+=((ct[1]+ct[2])/2.0);
        printf ("Case %d: ", ++cas);
        if ( sum >= 90 ) printf ("A");
        else if ( sum >= 80 ) printf ("B");
        else if ( sum >= 70 ) printf ("C");
        else if ( sum >= 60 ) printf ("D");
        else printf ("F");

        printf ("\n");
    }
    return 0;
}
