#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    int n,tmp;
    bool blank=false;
    while(scanf("%d",&n),n){

        if(blank) printf("\n");
        blank=true;

        vector <int> arr;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            arr.push_back(tmp);
        }
        sort(arr.begin(),arr.end());
        vector <int> v(n,1);
        fill(v.begin()+6 , v.end(),0);

        do{
           int i=0;
           for(; i<n; i++)
             if(v[i]){
                printf("%d",arr[i]);
                break;
             }
           i++;
           for(; i<n; i++)
             if(v[i])
                printf(" %d",arr[i]);
            printf("\n");
        }while(next_permutation(v.begin(), v.end(), greater<int>()));
    }
    return 0;
}
