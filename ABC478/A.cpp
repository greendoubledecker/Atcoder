#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
	ll n,m; cin >> n >> m;
	for(ll i = 0; i < m%n; ++i){
		cout << m/n + 1 << endl;
	}
	for(ll j = m%n; j < n; ++j){
		cout << m/n << endl;
	}
}
