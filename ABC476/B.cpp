#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
string s,t;
int main(){
	cin >> n >> s >> t;
	for(ll i = 0; i < n; ++i){
		if(s[i] != t[i] && t[i] != '*'){
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
}
