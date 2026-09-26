#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n,s,L;
	cin >> n >> s >> L;
	vector<ll> a;
	for(ll i = 0; i < n-1; ++i){
		ll x;
		cin >> x;
		a.push_back(x);
	}
	ll dist = 0;
	ll ans = 0;
	for(ll numLeft = 1; dist <= L && numLeft < s; ++numLeft){
		dist += a[s - numLeft - 1];
		if(dist >L)break;
		//cout << numLeft  << " left\n";
		ll newdist = dist;
		ans = max(ans, numLeft + 1);
		for(ll numright = 1; newdist <= L && numright - numLeft <= n-s; ++numright){
			//cout << numright << " right\n";
			newdist += a[s + numright - numLeft - 2];
			if(newdist >L)break;
			//cout << "dist = " << newdist << endl;
			ans = max(ans, numLeft + max(0ll, numright - numLeft) + 1);
		}
		//cout << "eit\n";
		//cout <<  "ind " << s - numLeft - 1 << endl;
		//cout << "ewe\n";
	}
	dist = 0;
	for(ll numRight = 1; dist <= L && numRight <= n-s; ++numRight){
		dist += a[s +numRight - 2];
		if(dist >L)break;
		//cout << numRight << "right\n";
		ll newdist = dist;
		ans = max(numRight + 1, ans);
		for(ll numLeft = 1; newdist <= L && numLeft - numRight < s; ++numLeft){
			//cout << numLeft << "left\n";
			newdist += a[s - (numLeft-numRight)-1];
			if(newdist >L)break;
			ans = max(ans, numRight + max(0ll, numLeft - numRight) + 1);
		}
		//cout << "exit\n";

	}
	cout<< ans << endl;
}
