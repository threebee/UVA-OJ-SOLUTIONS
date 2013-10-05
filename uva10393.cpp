#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	map<char, int> Map;
	Map['q']=1; Map['a']=1; Map['z']=1;
	Map['w']=2; Map['s']=2; Map['x']=2;
	Map['e']=3; Map['d']=3; Map['c']=3;
	Map['r']=4; Map['f']=4; Map['v']=4;
	Map['t']=4; Map['g']=4; Map['b']=4;
	Map['y']=7; Map['h']=7; Map['n']=7;
	Map['u']=7; Map['j']=7; Map['m']=7;
	Map['i']=8; Map['k']=8; Map[',']=8;
	Map['o']=9; Map['l']=9; Map['.']=9;
	Map['p']=10; Map[';']=10; Map['/']=10;

	int m,n,i,j,temp,l;
	while (scanf("%d %d",&m,&n)==2) {
		bool flag[11];
		memset(flag, true, sizeof flag);
		while(m--){ scanf("%d",&temp); flag[temp]=false; }
		vector<string> Vec(n);
		vector<string> Ans,Print;
		l=0;
		for(i=0;i<n;i++) {
            cin>>Vec[i];
			l=max(l,(int)Vec[i].length());
		}
		do {
			for(i=0;i<n;i++) {
				bool f1=true;
				if((int)Vec[i].length()==l) {
					for(j=0;j<l;j++){
						if(!flag[Map[Vec[i][j]]]){
							f1=false;
                            break;
						}
					}
					if(f1) Ans.push_back(Vec[i]);
				}
			}
			if (Ans.size()>0) break;
		}while(l--);

		int s = Ans.size();
		sort(Ans.begin(), Ans.end());
		for(i=0;i<s;i++){
			if (i > 0 && Ans[i] == Ans[i - 1]) continue;
			else Print.push_back(Ans[i]);
		}

		s=Print.size();
		printf("%d\n",s);
		for(i=0;i<s;i++) cout<<Print[i]<<endl;
	}
	return 0;
}
