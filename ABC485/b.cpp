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
	ll x,y;
	cin >> y >> x;
	vector<vector<bool>> v(y, vector<bool>(x));
	for(ll i = 0; i < y; ++i){
		for(ll j = 0; j < x; ++j){
			char c;
			cin >> c;
			v[i][j] = c == 'x';
		}
	}
	for(ll i = 0; i < y; ++i){
		//faucet
		bool f = true;
		for(ll j = 0; j < x; ++j) f = f && v[i][j];
		if(f){
			cout << "Faucet " << ++i;
			return 0;
		}
	}
	for(ll i = 0; i < x; ++i){
		//drain
		bool d = true;
		for(ll j = 0; j < y; ++j) d = d && v[j][i];
		if(d){
			cout << "Drain " << ++i;
			return 0;
		}
	}
}
