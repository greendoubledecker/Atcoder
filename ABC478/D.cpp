#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#else
#define debug(x)
#endif
int main(){
	ll n,q;
	cin >> n >> q;
	vector<vector<pair<ll,bool>>> events(q);
	for(ll i = 0; i < q; ++i){
		ll l,r,x;
		cin >> l >> r >> x;
		--x;
		--l;
		--r;
		events[x].push_back({l,0}); //0 = start 1 = end
		events[x].push_back({r,1});
	}
	vector<ll> da(n+1, 0);
	for(ll i = 0; i < q; ++i){
		debug(i);
		ll counter = 0;
		sort(events[i].begin(), events[i].end());
		for(ll j = 0; j < events[i].size(); ++j){
			debug(j);
			if(events[i][j].second){
				--counter;
				if(!counter){
					da[events[i][j].first + 1]--;
				}
			}else{
				++counter;
				if(counter == 1){
					da[events[i][j].first]++;
				}
			}
			debug(counter);
		}
	}
	ll sum = 0;
	for(ll i = 0; i < n; ++i){
		if(i)cout << ' ';
		sum += da[i];
		cout << sum;
	}
	cout << endl;
}
