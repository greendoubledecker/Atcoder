#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> fact(3e6+10);
vector<ll> inv(3e6+10);
ll power(ll a, ll b){
	ll res = 1;
	a %= 998244353;
	while(b>0){
		if(b&1){
			res = res*a%998244353;
		}
		a = a*a%998244353;
		b>>=1;
	}
	return res;
}
void precompute(){
	fact[0]=1;
	for(ll i = 1; i < fact.size(); ++i){
		fact[i]=fact[i-1]*i%998244353;
	}
	inv[3e6+9] = power(fact[3e6+9],998244351);
	for(ll i = 3e6+8; i >= 0; --i){
		inv[i]=inv[i+1]*(i+1)%998244353;
	}
}
ll choose(ll n, ll r){
	if(r>n || r<0)return 0;
	return fact[n]%998244353*inv[r]%998244353*inv[n-r]%998244353;
}
void tc(){
	precompute();
	ll x1,x2,x3;
	cin >> x1 >> x2 >> x3;
	ll ans = 0;
	for(ll a = 1; a <= x2+1; ++a){
		ll b = x2+1-a;
		ll add = choose(x1-1, a-1)%998244353;
		add = add*choose(x3+b-1, b-1)%998244353;
		add = add*choose(x2+1, a)%998244353;
		//cout << "with a = " << a << ": " <<add <<endl;
		ans += add;
		ans %= 998244353;
	}
	cout << ans << endl;
}
int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
