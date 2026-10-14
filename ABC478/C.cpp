#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n,k;
	cin >> n >> k;
	vector<ll> a(n);
	for(ll i = 0; i < n; ++i){
		cin >> a[i];
	}
	vector<ll> prefMax(n), sufMin(n);
	prefMax[0] = 0;
	sufMin[n-1] = LLONG_MAX;
	for(ll i = 1; i < n; ++i){
		prefMax[i] = max(prefMax[i-1], a[i-1]);
		//cout << "prefmax: " << prefMax[i] << endl;
	}
	for(ll i = n-2; i >= 0; --i){
		sufMin[i] = min(sufMin[i+1], a[i+1]);
		//cout << "sufmin: " << sufMin[i] << endl;
	}
	//cout << "eg5rihs\n";
	ll left = 0;
	while(left <= n-1 && a[left] <= sufMin[left]) ++left;
	--left;
	//cout << "bluh\n";
	ll right = n-1;
	while(right >= 0 && a[right] >= prefMax[right]) --right;
	++right;
	//cout << right  << ' ' << left << endl;
	if(right - left <= k + 1) cout << "Yes\n";
	else cout << "No\n";
}
	/*
	ll frontSort = n;
	for(ll i = 0; i < n-1; ++i){
		if(a[i] > a[i+1]){
			frontSort = i + 1;
			break;
		}
	}
	ll endSort = n;
	reverse(a.begin(), a.end());
	for(ll i = 0; i < n-1; ++i){
		if(a[i] < a[i+1]){
			endSort = i + 1;
			break;
		}
	}
	if(frontSort + endSort < n-k+2){
		cout << "No\n";
	}else{
		cout << "Yes\n";
	}
	*/
