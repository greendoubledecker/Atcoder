#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	ll o = 0,t = 0,h=0;
	for(ll i = 0; i < n; ++i){
		ll x;
		cin >> x;
		x = 1000 - (x%1000);
		h += (x%1000)/100;
		t += (x%100)/10;
		o += x%10;
	}
	cout << o << ' '<< t <<' '  << h << endl;;
}
