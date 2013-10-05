#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

#define INF 10000000
#define PI acos(-1)
#define radius 6378

typedef vector <int> vi;
typedef vector <double> vd;
typedef pair <double,int> di;
typedef vector <di> vdi;
typedef greater <di> gdi;

vector <vdi> AdjList;

struct point { double x,y; };

double gcDistance(double pLat, double pLong,double qLat, double qLong) {
    pLat*=PI/180; pLong*=PI/180; qLat*=PI/180; qLong*=PI/180;
    double a= cos(pLat)*cos(pLong)*cos(qLat)*cos(qLong) +
           cos(pLat)*sin(pLong)*cos(qLat)*sin(qLong) +
           sin(pLat)*sin(qLat);
    if(a>1.) a=1.;              //limit of acos()
    if(a<-1.) a=-1.;            //limit of acos()
    return acos(a)*radius;
}

double Distance(point a,point b){
     double plat = a.x;
     double plong= a.y;
     double qlat = b.x;
     double qlong= b.y;
     return gcDistance(plat,plong,qlat,qlong);
}


int main(){
    bool blank=false;
    int n,m,query,cas=0;
    while(scanf("%d %d %d",&n,&m,&query),(n||m||query)){
        AdjList.assign(n,vdi());
        map <string,point> smp;
        map <string,int> mp;
        string str1,str2;
        point tmp;

        for(int i=0;i<n;i++){
            cin>>str1>>tmp.x>>tmp.y;
            mp[str1]=i;
            smp[str1]=tmp;
        }

        for(int i=0;i<m;i++){
            cin>>str1>>str2;
            AdjList[mp[str1]].push_back(di(round(Distance(smp[str1],smp[str2])),mp[str2]));
        }

        if(blank) printf("\n"); blank=true;
        printf("Case #%d\n",++cas);

        for(int i=0;i<query;i++){

            cin>>str1>>str2;
            priority_queue <di,vdi,gdi> pq;
            pq.push(di(0,mp[str1]));
            vd dist(n,INF);
            dist[mp[str1]]=0.0;

            while(!pq.empty()){
                di u=pq.top();  pq.pop();
                double d=u.first;
                int s=u.second;
                for(int j=0;j<(int)AdjList[s].size();j++){
                    di v=AdjList[s][j];
                    if(dist[v.second] > dist[s] + v.first){
                        dist[v.second] = dist[s] + v.first;
                        pq.push(di(dist[v.second],v.second));
                    }
                }
            }

            if(dist[mp[str2]]==INF) printf("no route exists\n");
            else printf("%.0lf km\n",dist[mp[str2]]);
        }
    }
    return 0;
}
