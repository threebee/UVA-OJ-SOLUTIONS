#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector <string> vs;
string val,line;
int t,n,m;

void solve(string res, int c, int a, int lim) {
    if(c==lim)
       cout<<res<<endl;
    else
       for(int i=a ; i<vs.size() ; i++)
           c == 0 ? solve(vs[i], c+1, i+1, lim) : solve(res + ", " + vs[i], c+1, i+1, lim);
}


int main(){
    scanf("%d\n",&t);
    while(t--){
        vs.clear();
        getline(cin,val);

        while (getline(cin, line), line != "") vs.push_back(line);

        if (sscanf(val.c_str(),"%d %d",&n,&m) == 2) {
            for (int i=n ; i<=m ; i++) {
                printf("Size %d\n", i);
                solve("", 0, 0, i);
                printf("\n");
            }
        }
        else if(sscanf(val.c_str(),"%d",&n) == 1) {
            printf("Size %d\n", n);
            solve("", 0, 0, n);
            printf("\n");
        }
        else {
            for (int i=1;i<=vs.size();i++){
                printf("Size %d\n", i);
                solve("", 0, 0, i);
                printf("\n");
            }
        }
        if (t) printf("\n");
    }
    return 0;
}
