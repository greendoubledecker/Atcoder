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
	ll n,m;
	cin >> n >> m;
	vector<ll> cnt(n);
	vector<map<ll, ll>> second(n); //[first][second] = num;
	for(ll i = 0; i < m; ++i){
		ll a,b;
		cin >> a >> b;
		--a;
		--b;
		++cnt[a];
		++second[a][b];
	}
	ll maxx = -1, next = -1;
	ll val = -1, nextval = -1;
	for(ll i = 0; i < n; ++i){
		if(cnt[i] > val){
			nextval = val;
			next = maxx;
			val = cnt[i];
			maxx = i;
		}else if(cnt[i] > nextval){
			next = i;
			nextval = cnt[i];
		}
	}
	debug(maxx);
	debug(next);
	debug(val);
	debug(nextval);
	for(ll x = 0; x < n; ++x){
		ll newmaxx = -1, newval = -1;
		for(auto p : second[x]){
			if(p.second + cnt[p.first] > newval){
				newmaxx = p.first;
				newval = p.second + cnt[p.first];
			}
		}
		if(maxx == x){
			if(newval > nextval) cout << newmaxx + 1 << endl;
			else if(newval == nextval) cout << min(newmaxx, next) + 1 << endl;
			else cout << next + 1 << endl;
		}else{
			if(newval > val) cout << newmaxx + 1 << endl;
			else if(newval == val) cout << min(newmaxx, maxx) + 1 << endl;
			else cout << maxx + 1 << endl;
		}
	}
}
