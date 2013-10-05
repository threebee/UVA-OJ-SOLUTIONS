#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  int t;
  vector <string> input;
  map <string,int> mp;
  char in[100],temp1[100];
  scanf("%d",&t);
  while(t--){
        scanf("%s",in);
        gets(temp1);
        if(!mp[in]) input.push_back(in);
        mp[in]++;
  }
  sort(input.begin(),input.end());
  for(int i=0;i<input.size();i++)
    printf("%s %d\n",input[i].c_str(),mp[input[i]]);
  return 0;
}
