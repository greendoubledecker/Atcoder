#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#define debugVec(x) cout << #x << ": "; for(auto moo : x) cout << moo << ' '; cout << endl;
#define debug2d(x) cout << #x << ":\n"; for(auto moo : x){for(auto mooo : moo) cout << mooo << ' ';cout << endl;}
#define printLocal(x) cout << x << endl;
#else
#define debug(x)
#define debugVec(x)
#define debug2d(x)
#define printLocal(x)
#endif
int main(){
	ll n;
	cin >> n;
	vector<vector<ll>> right(n+1); //right ends of the colour
	vector<vector<ll>> left(n+1);
	vector<ll> v(n);
	ll prev = n;
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		--x;
		v[i] = x;
		if(x != prev){
			left[x].push_back(i);
			right[prev].push_back(i-1);
		}
		prev = x;
	}
	right[prev].push_back(n-1);
	debug2d(right);
	debug2d(left);
	printLocal("q3r3g");
	for(ll i = 0; i < n; ++i){
		auto x = upper_bound(left[v[i]].begin(), left[v[i]].end(), i);
		printLocal("weewewew");
		ll lhs = -1;
		if(x != left[v[i]].begin()) lhs = *(x-1)-1;
		debug(lhs);
		x = lower_bound(right[v[i]].begin(), right[v[i]].end(), i);
		ll rhs = n;
		if(x != right[v[i]].end()) rhs = *x+1;
		debug(rhs);
		if(lhs < 0) cout << rhs - i << endl;
		else if(rhs >= n) cout << i - lhs << endl;
		else cout << min(rhs - i, i - lhs) << endl;
	}
}
