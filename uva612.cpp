#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int counts;
char a[500];

void mergenow(int left,int mid,int right){
    int i=left,j=mid+1,k=0;
    int b[right-left+1];
    while(i<=mid && j<=right){
        if(a[i]<=a[j]) b[k++]=a[i++];
        else  b[k++]=a[j++],counts+=(mid-i+1);
    }
    while(i<=mid)   b[k++]=a[i++];
    while(j<=right) b[k++]=a[j++];
    for(i=left,k=0;i<=right;i++,k++) a[i]=b[k];
}

void mergesort(int left,int right){
    int mid = (left+right)/2;
    if(left<right){
        mergesort(left,mid);
        mergesort(mid+1,right);
        mergenow(left,mid,right);
    }
}

struct DNA{
    string sequence;
    int length;
};

bool cmp(DNA x,DNA y){ return x.length<y.length; }

int main(){
  int t,n,m,i;
  vector <DNA> v;
  scanf("%d",&t);
  while(t--){
      v.clear();
      scanf("%d %d",&n,&m);
      for(i=0;i<m;i++){
        scanf("%s",a);
        string tmp=(string)a;
        counts=0;
        mergesort(0,n-1);
        DNA d;
        d.sequence=tmp;
        d.length=counts;
        v.push_back(d);
      }
      stable_sort(v.begin(),v.end(),cmp);
      for(i=0;i<m;i++) printf("%s\n",v[i].sequence.c_str());
      if(t) printf("\n");
  }
  return 0;
}

