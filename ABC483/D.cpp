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
ll n;
int main(){
	cin >> n;
	vector<ll> a(n);
	for(ll &i : a) cin >> i;
	vector<ll> ps(n+1, 0);
	for(ll i = 0; i < n; ++i){
		ps[i+1] = ps[i] + a[i];
	}
	vector<ll> smax(n+1, 0); //from index onwards
	for(ll i = n - 1; i >= 0; --i){
		smax[i] = max(smax[i+1], ps[i+1]);
	}
	vector<ll> smin(n+1, LLONG_MAX);
	for(ll i = n - 1; i >= 0; --i){
		smin[i] = min(smin[i+1], ps[i+1]);
	}
	vector<ll> pmax(n+1, 0); //before index
	for(ll i = 0; i < n; ++i){
		pmax[i+1] = max(pmax[i], ps[i+1]);
	}
	vector<ll> pmin(n+1, 0);
	for(ll i = 0; i < n; ++i){
		pmin[i+1] = min(pmin[i], ps[i+1]);
	}
	debugVec(ps);
	debugVec(smax);
	debugVec(smin);
	debugVec(pmax);
	debugVec(pmin);
	ll ans = pmax[n] - pmin[n];
	for(ll flip = 0; flip < n; ++flip){
		ll maxx = max(smax[flip] - 2*a[flip], pmax[flip]);
		ll minn = min(smin[flip] - 2*a[flip], pmin[flip]);
		debug(flip);
		debug(maxx);
		debug(minn);
		ans = max(ans, maxx-minn);
	}
	cout << ans + 1 << endl;
}
