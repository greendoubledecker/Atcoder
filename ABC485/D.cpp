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
	string s;
	cin >> s;
	bool a=0,b=0,c=0;
	ll leftest, rightest;
	for(ll i = 0; i < n; ++i){
		a = a || s[i] == 'A';
		b = b || s[i] == 'B';
		c = c || s[i] == 'C';
		if(a&&b&&c){
			leftest = i;
			break;
		}
	}
	a=0,b=0,c=0;
	for(ll i = n-1; i >=0; --i){
		a = a || s[i] == 'A';
		b = b || s[i] == 'B';
		c = c || s[i] == 'C';
		if(a&&b&&c){
			rightest = i;
			break;
		}
	}
	debug(leftest);
	debug(rightest);
	ll l = leftest+1, r = leftest+1;
	ll ans = 0;
	ll as = 0, bs = 0, cs = 0;
	if(s[r] == 'A') ++as;
	if(s[r] == 'B') ++bs;
	if(s[r] == 'C') ++cs;
	while(r <= rightest){
		bool flg = 0;
		while(!(as&&bs&&cs)){ //r is the first one where it works, so divider must be after r and before rightest
			++r;
			if(r >= rightest){
				flg = true;
				break;
			}
			if(s[r] == 'A') ++as;
			if(s[r] == 'B') ++bs;
			if(s[r] == 'C') ++cs;
			debug(r);
			debug(as);
			debug(bs);
			debug(cs);
		}
		if(flg) break;
		debug(l);
		debug(r);
		ans += rightest-r;
		++l;
		if(s[l-1] == 'A') --as;
		if(s[l-1] == 'B') --bs;
		if(s[l-1] == 'C') --cs;
	}
	cout<< ans << endl;
}
