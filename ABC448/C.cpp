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
bool sot(pair<ll, ll> a, pair<ll, ll > b){
	return a.first < b.first;
}
int main(){
	ll t=1;
	//cin >> t;
	while(t--){
		ll n,q;
		cin >> n >> q;
		vector<pair<ll, ll>> balls(n);
		for(ll i = 0; i < n; ++i){
			ll w;
			cin >> w;
			balls[i].first = w;
			balls[i].second = i;
		}
		sort(balls.begin(), balls.end(), sot);
		/*
		for(pair<ll, ll> i : balls){
			cout << i.first << ' ';
		}
		*/
		while(q--){
			ll s;
			cin >> s;
			set<ll> st;
			while(s--){
				ll q;
				cin >> q;
				st.insert(q - 1);
			}
			for(pair<ll, ll> i : balls){
				if(!st.count(i.second)){
					cout << i.first << endl;
					break;
				}
			}
		}
	}
}
