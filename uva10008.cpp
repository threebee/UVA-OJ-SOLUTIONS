#include <cstdio>
#include <cctype>
#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,char> ic;

bool myfunction(ic x,ic y) {
    if(x.first>y.first)
        return (x.first>y.first);
    else
        return (x.second<y.second);
}

int main(){
    int n,a[26];
    char c;
    memset(a,0,sizeof(a));
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        while((c=getchar())!='\n'){
            if(isalpha(c))
               a[toupper(c)-65]++;
        }
    }
    vector <ic> ans;
    for(int i=0;i<26;i++)
        if(a[i])  ans.push_back(ic(a[i],(char)(i+65)));
    sort(ans.begin(),ans.end(),myfunction);

    for(int i=0;i<ans.size();i++){
        ic b=ans[i];
        printf("%c %d\n",b.second,b.first);
    }

    return 0;
}
