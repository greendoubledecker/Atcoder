#include <bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> factors(ll n){
	vector<ll> ans;
	for(ll i = 1; i < sqrt(n); ++i){ //O(sqrt(n))
		if(n % i == 0){
			ans.push_back(i);
			ans.push_back(n / i);
		}
	}
	if((ll)sqrt(n) * (ll)sqrt(n) == n){
		ans.push_back(sqrt(n));
	}
	return ans;
}
map<ll, ll> primeFactorize(ll n){
	map<ll, ll> ans;
	while(n % 2 == 0){
		++ans[2];
		n /= 2;
	}
	for(ll i = 3; i * i <= n; i += 2){
		while(n % i == 0){
			++ans[i];
			n /= i;
		}
	}
	if(n == 1) return ans;
	++ans[n];
	return ans;
}
struct Node{
	ll index = 0;
	ll dist = 1'000'000'000'000'000'000LL;
	vector<pair<Node*, ll>> connections;
	bool finalised = false;
};
void connect(Node* a, Node* b, ll cost){
	a -> connections.push_back({b, cost});
}
void bidirConnect(Node* a, Node* b, ll cost){
	a -> connections.push_back({b, cost});
	b -> connections.push_back({a, cost});
}
struct Compare{
	bool operator()(const Node* n1, const Node* n2){
		return n1 -> dist > n2 -> dist;
	}
};
void dijkstra(Node* start){
	priority_queue<Node*, vector<Node*>, Compare> pq;
	start -> dist = 0;
	pq.push(start);
	while(!pq.empty()){
		Node* cur = pq.top();
		pq.pop();
		if(cur -> finalised){
			continue;
		}else{
			cur -> finalised = true;
			for(pair<Node*, ll> &edge : cur -> connections){
				Node* next = edge.first;
				if(!next -> finalised && cur -> dist + edge.second < next -> dist){
					next -> dist = cur -> dist + edge.second;
					pq.push(next);
				}
			}
		}
	}
}
//END
int main(){
	ll t = 1;
	//cin >> t;
	while(t--){
		string a,b;
		cin >> a >> b;
		string c,d;
		for(ll i = 0; i < a.size(); ++i){
			char ch = a[i];
			if(ch != 'A') c.push_back(ch);
		}
		for(ll i = 0; i < b.size(); ++i){
			char ch = b[i];
			if(ch != 'A') d.push_back(ch);
		}
		if(c!=d){cout << "-1\n";}
		else{
			vector<ll> alens = {0}, blens = {0};
			for(ll i = 0; i < a.size(); ++i){
				if(a[i] == 'A'){
					alens[alens.size() - 1]++;
				}else{
					alens.push_back(0);
				}
			}
			for(ll i = 0; i < b.size(); ++i){
				if(b[i] == 'A'){
					blens[blens.size() - 1]++;
				}else{
					blens.push_back(0);
				}
			}
			ll ans = 0;
			for(ll i = 0; i < alens.size(); ++i){
				ans += max(alens[i] - blens[i], blens[i] - alens[i]);
			}
			cout << ans << '\n';
		}
	}
}
