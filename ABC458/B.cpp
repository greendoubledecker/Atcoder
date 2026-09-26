#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
void tc(){
	ll n, m;
	cin >> n >> m;
	for(ll i = 0; i < n; ++i){
		for(ll j = 0; j < m - 1; ++j){
			cout << 4 - (i == 0) - (j == 0) - (i == n - 1) - (j == m - 1) << ' ';
		}
		ll j = m - 1;
		cout << 4 - (i == 0) - (j == 0) - (i == n - 1) - (j == m - 1);
		cout << endl;
	}
}
int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
