// in queue

#include <cstdio>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <cctype>
#include <climits>
using namespace std;
#define LL long long int

map <int,int> mp;
int nums [100];
LL fibs [100];

int main(){
  int a[]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,
           121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,
           63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903};
  int i,t,n,l,maxi;
  for(i=0;i<46;i++) mp[a[i]]=i;
  scanf("%d",&t);
  while(t--){
        scanf("%d",&n);
        maxi=INT_MIN;
        for(i=0;i<n;i++){
            scanf("%d",&nums[i]);
            if(maxi<nums[i]) maxi=nums[i];
        }
        getchar();
        char str[110];
        gets(str);
        char output[110];
        memset(output,' ',sizeof output);
        output[mp[maxi]+1]=0;

        int str_len = 0;
        for (i=0; i<n; i++){
            while(!isupper(str[str_len])) str_len++;
            output[mp[nums [i]]]=str[str_len];
            str_len++;
        }
        printf("%s\n",output);
  }
  return 0;
}
