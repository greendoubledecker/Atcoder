#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll n;
	cin >> n;
	ll t;
	cin >> t;
	
	vector<ll> times(n);
	for(ll i = 0; i < n; ++i){
		cin >> times[i];
	}
	ll last = -200;
	ll count = 0;
	for(int i = 0; i < n; ++i){
		if(times[i] > last + 100){
			last = times[i];
			++count;
		}
	}
	if(last > t - 100){
		t += 100 - (t - last);
	}
	cout << t - 100 * count << endl;
}
