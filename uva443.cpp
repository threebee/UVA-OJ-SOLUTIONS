#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef long long int lli;
set <lli> st;

int main(){
    //freopen("out.txt","w",stdout);
    st.clear();
    st.insert(1);
    set <lli> :: iterator i=st.begin();
    while(st.size()<7000){
        st.insert(*i*2);
        st.insert(*i*3);
        st.insert(*i*5);
        st.insert(*i*7);
        *i++;
    }
    vector <lli> vec(st.begin(),st.end());
    sort(vec.begin(),vec.end());
    lli n;
    while(scanf("%lld",&n),n){
        printf("The %lld",n);
        if(n%100==11 || n%100==12 || n%100==13) printf("th ");
        else if(n%10==1)      printf("st ");
        else if(n%10==2) printf("nd ");
        else if(n%10==3) printf("rd ");
        else             printf("th ");
        printf("humble number is %lld.\n",vec[n-1]);
    }
    return 0;
}
