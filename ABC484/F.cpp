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
vector<ll> minst, maxst;
ll l(ll node){
	return node*2;
}
ll r(ll node){
	return node*2+1;
}
ll p(ll node){
	return node/2;
}
ll nextPow(ll node){
	ll ans = 1;
	while(ans < node) ans <<= 1;
	return ans;
}
ll qwery(ll left, ll right, bool which){ //0 = min, 1 = max
	if(left > right) return 0;
	left += nextPow(n); right += nextPow(n);
	if(which){
		ll ans = -LLONG_MAX;
		while(left <= right){
			if(left%2){
				ans = max(ans, maxst[left]);
				++left;
			}
			if(!(right%2)){
				ans = max(ans, maxst[right]);
				--right;
			}
			left = p(left);
			right = p(right);
		}
		return ans;
	}else{
		ll ans = LLONG_MAX;
		while(left <= right){
			if(left%2){
				ans = min(ans, minst[left]);
				++left;
			}
			if(!(right%2)){
				ans = min(ans, minst[right]);
				--right;
			}
			left = p(left);
			right = p(right);
		}
		return ans;
	}
}
void update(ll pos, ll val, bool which){
	pos += nextPow(n);
	if(which){
		maxst[pos] = val;
		while(pos > 1){
			pos = p(pos);
			maxst[pos] = max(maxst[l(pos)], maxst[r(pos)]);
		}
	}else{
		minst[pos] = val;
		while(pos > 1){
			pos = p(pos);
			minst[pos] = min(minst[l(pos)], minst[r(pos)]);
		}
	}
}
int main(){
	ll q;
	cin >> n >> q;
	minst.assign(nextPow(2*n), 1e17);
	maxst.assign(nextPow(2*n), -2);
	for(ll i = 0; i < n; ++i){
		ll a;
		cin >> a;
		update(i,a,1);
		if(a == -1){
			update(i,1e16,0);
		}else{
			update(i,a,0);
		}
	}
	while(q--){
		//debugVec(minst);
		//debugVec(maxst);
		ll query;
		cin >> query;
		if(query == 2){
			ll l,r;
			cin >> l >> r;
			--l;
			--r;
			ll maxxx = qwery(l,r,1);
			ll minnn = qwery(l,r,0);
			debug(maxxx);
			debug(minnn);
			if(maxxx == minnn || (maxxx == -1 && minnn == 10000000000000000)) cout << "Yes\n";
			else cout << "No\n";
		}else{
			ll i,x;
			cin >> i >> x;
			--i;
			update(i,x,1);
			if(x == -1){
				update(i,1e16,0);
			}else{
				update(i,x,0);
			}
		}
	}
}
