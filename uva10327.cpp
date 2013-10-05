#include <iostream>
#include <cstdio>
using namespace std;

int counts,a[100010];

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

int main(){
  int n,i;
  while(scanf("%d",&n)==1){
      for(i=0;i<n;i++) scanf("%d",&a[i]);
      counts=0;
      mergesort(0,n-1);
      printf("Minimum exchange operations : %d\n",counts);
  }
  return 0;
}
