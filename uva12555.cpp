#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	int t,a,b,cnt=0;
	cin>>t;
	while(t--){
		cin>>a>>s;
		b = s.length()>3 ? (int)s[3]-'0' : 0;
		cout<<"Case "<<++cnt<<": "<<a*0.5 + b*0.05<<endl;
	}
	return 0;
}
