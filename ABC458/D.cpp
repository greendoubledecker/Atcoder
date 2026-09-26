#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
void tc(){
	ll x;
	ll q;
	cin >> x >> q;
	vector<ll> v1(1, x);
	make_heap(v1.begin(), v1.end());
	vector<ll> v2(0);
	make_heap(v2.begin(), v2.end());
	while(q--){
		ll a, b;
		cin >> a >> b;
		if(a < v1.front()){
			v1.push_back(a);
			push_heap(v1.begin(), v1.end());
		}else{
			v2.push_back(-a);
			push_heap(v2.begin(), v2.end());
		}
		//cout << "ywyuger" << endl;
		if(v1.size() > v2.size() + 1){
			pop_heap(v1.begin(), v1.end());
			v2.push_back(-v1[v1.size() - 1]);
			v1.pop_back();
			push_heap(v2.begin(), v2.end());
		}
		if(v2.size() > v1.size() + 1){
			pop_heap(v2.begin(), v2.end());
			v1.push_back(-v2[v2.size() - 1]);
			v2.pop_back();
			push_heap(v1.begin(), v1.end());
		}
		//cout << "erg" << endl;
		if(b < v1.front()){
			v1.push_back(b);
			push_heap(v1.begin(), v1.end());
		}else{
			v2.push_back(-b);
			push_heap(v2.begin(), v2.end());
		}
		if(v1.size() > v2.size() + 1){
			pop_heap(v1.begin(), v1.end());
			v2.push_back(-v1[v1.size() - 1]);
			v1.pop_back();
			push_heap(v2.begin(), v2.end());
		}
		if(v2.size() > v1.size() + 1){
			pop_heap(v2.begin(), v2.end());
			v1.push_back(-v2[v2.size() - 1]);
			v2.pop_back();
			push_heap(v1.begin(), v1.end());
		}
		if(v1.size() > v2.size()){
			cout << v1.front();
		}else{
			cout << -v2.front();
		}
		cout << endl;
	}
}
int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		tc();
	}
}
