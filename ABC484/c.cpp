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
	vector<ll> a, b;
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		a.push_back(x);
	}
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		b.push_back(x);
	} //note: check if both are equal
	bool shiftR = true;
	ll i = 0;
	ll missing = -1;
	for(; i < n-1; ++i){
		if(b[i] != a[i]){
			if(b[i+1] != a[i]){
				shiftR = false;
			}
			break;
		}
	}
	missing = b[i];
	printLocal("first");
	debug(missing);
	debug(i);
	if(shiftR){
		for(; i < n-1; ++i){
			if(b[i+1] != a[i]){
				debug(i);
				if(b[i+1] != a[i+1]) shiftR = false;
				break;
			}
		}
		printLocal("2nd");
		debug(i);
	}
	if(shiftR){
		if(a[i] != missing) shiftR = false;
		++i;
		printLocal("in");
		for(; i < n; ++i){
			debug(i);
			if(b[i] != a[i]){
				shiftR = false;
				break;
			}
		}
	}

	bool shiftL = true;
	swap(a,b);
	i = 0;
	missing = -1;
	for(; i < n-1; ++i){
		if(b[i] != a[i]){
			if(b[i+1] != a[i]){
				shiftL = false;
			}
			break;
		}
	}
	printLocal("blah.");
	missing = b[i];
	debug(missing);
	if(shiftL){
		for(; i < n-1; ++i){
			if(b[i+1] != a[i]){
				if(b[i+1] != a[i+1]) shiftL = false;
				break;
			}
		}
	}
	printLocal("QEGR");
	debug(i);
	if(shiftL){
		debug(a[i]);
		if(a[i] != missing) shiftL = false;
		printLocal("in");
		++i;
		for(; i < n; ++i){
			if(b[i] != a[i]){
				shiftL = false;
				break;
			}
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if((shiftR || shiftL) && a == b) cout << "Yes\n";
	else cout << "No\n";
}
