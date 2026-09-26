#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
void tc(){
	string s;
	cin >> s;
	vector<ll> c;
	for(ll i = 0; i < s.size(); ++i){
		if(s[i] == 'C'){
			c.push_back(i);
		}
	}
	ll ans = 0;
	for(ll i = 0; i < c.size(); ++i){
		ans += min(c[i] + 1, (ll)s.size() - c[i]);
	}
	cout << ans << endl;
}
int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
