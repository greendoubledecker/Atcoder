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
	ll n;
	cin >> n;
	vector<ll> pos(n);
	for(ll& i : pos){
		cin >> i;
	}
	if(n == 1) cout << 0 << endl;
//- if(n == 2) cout << (pos[1] - pos[0])/2 << endl; i need to print it twice ooops.
//+ upsolve:
	if(n == 2) cout << (pos[1] - pos[0])/2 << (pos[1] - pos[0])/2 << endl;
	if(n <= 2) return 0;
	for(ll zombie = 0; zombie < n; ++zombie){
		if(zombie == 0){
			cout << max(pos[zombie + 1] - pos[0], pos[n-1] - pos[zombie]) / 2 << endl;
			continue;
		}
		if(zombie == n-1){
			cout << max(pos[zombie] - pos[0], pos[n-1] - pos[zombie - 1]) / 2 << endl;
			continue;
		}
		cout << min(max(pos[zombie] - pos[0], pos[n-1] - pos[zombie - 1]) / 2,
		max(pos[zombie + 1] - pos[0], pos[n-1] - pos[zombie]) / 2) << endl;
	}
}
