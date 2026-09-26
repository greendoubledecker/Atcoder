#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n,d; cin >> n >> d;
	vector<pair<ll, ll>> people(n);
	vector<ll> ans;
	for(ll i = 0; i < n; ++i){
		cin >> people[i].first;
		people[i].second = i;
	}
	sort(people.begin(), people.end());
	for(ll i = 1; i < n-1; ++i){
		if(people[i].first - people[i-1].first >= d && people[i+1].first - people[i].first >= d) ans.push_back(people[i].second + 1);
	}
	if(people[1].first - people[0].first >= d) ans.push_back(people[0].second + 1);
	if(people[n-1].first - people[n-2].first >= d) ans.push_back(people[n-1].second + 1);
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for(ll i = 0; i < ans.size(); ++i){
		if(i) cout << ' ';
		cout << ans[i];
	}
	cout << endl;
}
