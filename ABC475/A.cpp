#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	string s;
	cin >> s;
	for(ll i = 0; i < s.size(); ++i){
		if(i) cout << 'o';
		cout << s[i];
	}
	cout << endl;
}
