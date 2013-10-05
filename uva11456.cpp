#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
  int t;
  scanf("%d",&t);
  while(t--){
   int n,maxi=1;
   scanf("%d",&n);
   vector <int> v(n,0),lds(n,1),lis(n,1);
   for(int i=0;i<v.size();i++) scanf("%d",&v[i]);
   reverse(v.begin(), v.end());

   for(int i=0;i<v.size();i++)
      for(int j=0;j<i;j++){
        if(v[j]>v[i] && lds[i]<lds[j]+1) lds[i]=lds[j]+1;
        if(v[j]<v[i] && lis[i]<lis[j]+1) lis[i]=lis[j]+1;
      }

    for(int i=0;i<v.size();i++)
        maxi=max(lis[i]+lds[i]-1,maxi);
    printf("%d\n",maxi);
  }
  return 0;
}
/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int * LIS_Lengths(vector<int> a, int dir) {
    int* lis = new int[a.size()];
    memset(lis, sizeof(lis), 0);

    for (size_t i = 0; i < a.size(); i++) {
        int longest = 0;
        for (size_t j = 0; j < i; j++)
            if (a[j] > a[i] == dir && lis[j] > longest)
                longest = lis[j];
        lis[i] = longest + 1;
    }
    return lis;
}

int main() {
    int N, n, T;
    cin >> T;
    while (T-- && (cin >> N)) {
        vector<int> a;
        while (N-- && (cin >> n))
            a.push_back(n);
        reverse(a.begin(), a.end());

        int* lis = LIS_Lengths(a, 0);
        int* lds = LIS_Lengths(a, 1);

        int MAX_LIS = 0;
        for (size_t i = 0; i < a.size(); i++)
            MAX_LIS = max(lis[i] + lds[i] - 1, MAX_LIS);

        cout << MAX_LIS << endl;
    }
    return 0;
}
*/
