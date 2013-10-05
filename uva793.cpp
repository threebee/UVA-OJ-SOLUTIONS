//correct answer problem with output formatting

#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi pset;

void init(vi &pset,int n){
    pset.assign(n,0);
    for(int i=0;i<n;i++) pset[i]=i;
}

int find_set(int i){
 if(pset[i]==i) return i;
 else return pset[i]=find_set(pset[i]);
}

bool in_same_set(int i,int j){ return find_set(i)==find_set(j); }

void connect_set(int i,int j){ pset[find_set(i)]=find_set(j); }

int main(){
 int t;
 scanf("%d",&t);
 getchar();
 while(t--){
    int n;
    scanf("%d",&n);
    init(pset,n);
    char c,line[80];
    int u,v,count1=0,count2=0;
    getchar();
    while(gets(line) && sscanf(line,"%c %d %d",&c,&u,&v)==3){
         if(c=='c') connect_set(u,v);
         else{
            if(in_same_set(u,v)) count1++;
            else count2++;
         }
    }
    printf("%d,%d",count1,count2);
    if(t) printf("\n");
 }
 return 0;
}
