#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

vector <pair<double, ii> > edges;
vi pset;

void init(int N){
    pset.assign(N,0);
    for(int i=0;i<N;i++) pset[i]=i;
}

int find_set(int i){
    if(pset[i]==i) return pset[i];
    return pset[i]=find_set(pset[i]);
}

bool issameset(int i,int j){ return find_set(i)==find_set(j); }

void joinset(int i,int j){ pset[find_set(i)]=find_set(j); }

int t, x, y, N, M;
int cx[750], cy[750];

int main() {
    scanf("%d\n", &t);
    while (t--) {
        edges.clear();
        scanf("%d", &N);
        for(int i=0;i<N;i++){
            scanf("%d %d", &x, &y);
            cx[i] = x;
            cy[i] = y;
        }

        for(int i=0;i<N;i++){
            for (int j=i+1 ; j<N ; j++) {
                double dist = hypot((double)(cx[i] - cx[j]), (double)(cy[i] - cy[j]));
                edges.push_back(make_pair(dist, ii(i, j)));
            }
        }
        sort(edges.begin(), edges.end());
        init(N);
        scanf("%d", &M);
        while (M--) {
            scanf("%d %d", &x, &y);
            joinset(x-1, y-1);
        }

        bool flag=true;
        for (int i=0 ; i<edges.size() ; i++) {
            pair<double, ii> front = edges[i];
            if (!issameset(front.second.first, front.second.second)) {
                printf("%d %d\n", front.second.first+1, front.second.second+1);
                flag=false;
                joinset(front.second.first, front.second.second);
            }
        }
        if (flag) printf("No new highways need\n");
        if(t) printf("\n");
    }
}
