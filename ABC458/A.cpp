#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
void tc(){
	string s;
	cin >> s;
	ll n;
	cin >> n;
	for(ll i = 0; i < s.size(); ++i){
		if(i >= n && s.size() - i > n){
			cout << s[i];
		}
	}
}
int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
//which is correct: hamster or hampster?
//ummmmm...
//it's hamster.
