#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#define debugVec(x) cout << #x << ": "; for(auto moo : x) cout << moo << ' '; cout << endl;
#define debug2d(x) cout << #x << ":\n"; for(auto moo : x){for(auto mooo : moo) cout << mooo << ' ';cout << endl;}
#define printLocal(x) cout << x << '\n';
#else
#define debug(x)
#define debugVec(x)
#define debug2d(x)
#define printLocal(x)
#endif
int main(){
	ll n,q;
	cin >> n >> q;
	vector<ll> v(n);
	iota(v.begin(), v.end(), 1);
	for(ll i = 0; i < q; ++i){
		ll k;
		cin >> k;
		reverse(v.begin(), v.begin() + k);
		for(ll j = 0; j < k; ++j){
			v[j] *= -1;
		}
	}
	for(ll i : v) cout << i << endl;
}
