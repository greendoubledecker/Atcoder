#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n, v; cin >> n >> v;
	vector<ll> w(n);
	for(ll i = 0; i < n; ++i){
		cin >> w[i];
	}
	ll ans = 0;
	for(ll i = 0; i < n; ++i){
		for(ll j = i+1; j < n; ++j){
			for(ll k = j+1; k < n; ++k){
				if(i+j+k+3 <= v){
					ans = max(ans, w[i]+w[j]+w[k]);
				}
			}
		}
	}
	cout << ans << endl;
}
