/*
With only 2^12 subsets, you can easily brute force the solution. First, sort the numbers.
Then, try all possible subsets (bitshifting is the nicest way). When you find a subset with the requested sum,
make a string out of it, like "50+23+5", and add it to an output array. Make sure you have no duplicates in the
output array.
At the end, sort the output array descending and print it out. Luckily, '+' is lexicographically before '0',
so it suffices to just sort the strings and print them out.
*/

#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

bool cmp(int a,int b){ return a>b; }

int main(){
    int input[15],t,n,i,mask,mask_lim,sum;
    vector <string> vs;
    map <string,int> mp;

    while(scanf("%d %d",&t,&n),(t||n)){

        for(i=0;i<n;i++) scanf("%d",&input[i]);
        sort(input,input+n,cmp);

        vs.clear(); mp.clear(); mask=0;

        mask_lim=(1<<n);
        for(mask=0;mask < mask_lim;mask++){
            sum=0;
            for(i=0;i<n;i++) sum+=((1<<i) & mask) ? input[i] : 0 ;

            if(sum==t){
                string str="";
                for(i=0;i<n;i++){
                  if((1<<i) & mask){
                      ostringstream convert;
                      convert << input[i];
                      str+=convert.str();
                      break;
                  }
                }
                i++;
                for(;i<n;i++){
                  if((1<<i) & mask){
                    ostringstream convert;
                    str+='+';
                    convert << input[i];
                    str+=convert.str();
                  }
                }
               string temp=str;
               sort(temp.begin(),temp.end());
               if(!mp[temp]){
                  mp[temp]=1;
                  vs.push_back(str);
               }
            }
        }
        printf("Sums of %d:\n",t);
        sort(vs.rbegin(),vs.rend());
        if(!vs.size()) printf("NONE\n");
        else{
          for(i=0;i<vs.size();i++) cout<<vs[i]<<endl;
        }
    }
    return 0;
}
