#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n;
	cin >> n;
	ll first = 0, sec = 0, third = 0;
	for(ll i = 0; i < n; ++i){
		ll a;cin >> a;
		if(a >= first){
			third = sec;
			sec = first;
			first = a;
		}else if(a >= sec){
			third = sec;
			sec = a;
		}else if(a >= third) third = a;
		if(i >= 2) cout << third << endl;
	}
}
