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
	vector<vector<bool>> s(5, vector<bool>(5));
	ll maxx = 0;
	for(ll y = 0; y < 5; ++y){
		ll cnt = 0;
		for(ll x = 0; x < 5; ++x){
			char c;
			cin >> c;
			s[y][x] = c == 'o';
			cnt += s[y][x];
		}
		maxx = max(maxx, cnt);
	}
	for(ll x = 0; x < 5; ++x){
		ll cnt = 0;
		for(ll y = 0; y < 5; ++y){
			cnt += s[y][x];
		}
		maxx = max(maxx, cnt);
	}
	ll cnt = 0;
	for(ll i = 0; i < 5; ++i){
		cnt += s[i][i];
	}
	maxx = max(maxx, cnt);
	cnt = 0;
	for(ll i = 0; i < 5; ++i){
		cnt += s[i][5-i-1];
	}
	maxx = max(maxx, cnt);
	cout << 5-maxx << endl;
}
