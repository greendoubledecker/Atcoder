#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool rangeInclude(ll l1, ll r1, ll l2, ll r2){ //r2 is part of r1
	return l1 <= l2 && r1 >= r2;
}
int main(){
	ll q;
	string s,t;
	cin >> q >> s >> t;
	vector<pair<ll, ll>> ranges;
	if(t.size() > s.size()){
		while(q--){
			ll l, r;
			cin >> l >> r;
			cout << "No\n";
		}
		return 0;
	}
	for(ll i = 0; i <= s.size() - t.size(); ++i){
		bool flag = false;
		for(ll j = 0; j < t.size(); ++j){
			if(t[j] != s[i+j]){
				flag = true;
				break;
			}
		}
		if(!flag){
			//cout << "range at " << i << endl;
			ranges.push_back({i, i + t.size() - 1});
		}
	}
	while(q--){
		ll l,r;
		cin >> l >> r;
		--l;
		--r;
		//cout << "ferret\n";
		ll left = 0, right = ranges.size()-1, ans = -1;
		while(left <= right){
			ll mid = left + (right-left)/2;
			if(ranges[mid].first < l) left = mid + 1;
			else{
				right = mid - 1;
				ans = mid;
			}
		}
		if(ans == -1){
			cout << "No\n";
			continue;
		}
		//cout << "range is: " << ranges[ans].first << ' ' << ranges[ans].second;
		if(rangeInclude(l, r, ranges[ans].first, ranges[ans].second)){
			cout << "Yes\n";
		}else cout << "No\n";
	}
}
