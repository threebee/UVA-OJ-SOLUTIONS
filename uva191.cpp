#include <cstdio>
#include <iostream>
using namespace std;

struct point{
   double x,y;
   point(double _x,double _y){ x=_x; y=_y; }
};

int sig(point a,point b,point c){
   int x=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
   if(x==0) return 0;
   else if(x<0) return -1;
   else return 1;
}

bool in(point a,point b,point c,point d){
   if((c.x<=a.x && a.x<=d.x && c.y<=a.y && a.y<=d.y) || (c.x<=b.x && b.x<=d.x && c.y<=b.y && b.y<=d.y))
    return true;
   return false;
}

int main(){
    int n,x1,y1,x2,y2,x3,y3,x4,y4,counts;
    scanf("%d",&n);
    while(n--){
        counts=0;
        scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(x3>x4) std::swap(x3,x4);
        if(y3>y4) std::swap(y3,y4);
        point a(x1,y1),b(x2,y2),c(x3,y3),d(x4,y4),e(x3,y4),f(x4,y3);

        if(sig(a,b,c)!=sig(a,b,f) && sig(a,c,f)!=sig(b,c,f))  counts++;
        if(sig(a,b,f)!=sig(a,b,d) && sig(a,f,d)!=sig(b,f,d))  counts++;
        if(sig(a,b,e)!=sig(a,b,d) && sig(a,e,d)!=sig(b,e,d))  counts++;
        if(sig(a,b,c)!=sig(a,b,e) && sig(a,c,e)!=sig(b,c,e))  counts++;

        if(in(a,b,c,d))  printf("%c\n",'T');
        else{
            if(counts>=1)  printf("%c\n",'T');
            else    printf("%c\n",'F');
        }
    }
    return 0;
}
