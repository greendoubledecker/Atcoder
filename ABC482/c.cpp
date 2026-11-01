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
	ll h,w,n,q;
	cin >> h >> w >> n >> q;
	vector<ll> cntY(h+10, 0);
	vector<ll> cntX(w+10, 0);
	for(ll i = 0; i < n; ++i){
		ll r,c;
		cin >> r >> c;
		--r;
		--c;
		++cntY[r];
		++cntX[c];
	}
	vector<ll> psY(h+10, 0);
	vector<ll> psX(w+10, 0);
	for(ll i = 0; i < h; ++i){
		psY[i+1] = psY[i] + cntY[i];
	}
	for(ll i = 0; i < w; ++i){
		psX[i+1] = psX[i] + cntX[i];
	}
	while(q--){
		ll x,a,b;
		cin >> x >> a >> b;
		if(x-1){ // cols
			cout << psX[b] - psX[a-1] << endl;
		}else{
			cout << psY[b] - psY[a-1] << endl;
		}
	}
}
