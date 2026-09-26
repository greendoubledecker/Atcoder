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
	vector<Node*> connections;
	bool ans = false;
	bool visited = false;
	ll num = 0;
};

//END
set<ll> pass;
void dfs(Node* root){
	root ->visited = true;
	bool did = false;
	if(pass.count(root -> num)){
		root -> ans=true;
	}else{
		pass.insert(root -> num);
		did = true;
	}
	for(Node* p : root -> connections){
		if(p -> visited) continue;
		p -> ans = root -> ans;
		dfs(p);
	}
	if(did){
		pass.erase(root -> num);
	}
}
vector<Node*> tree;
int main(){
	ll t=1;
	//cin >> t;
	while(t--){
		ll n;
		cin >> n;
		for(ll i = 0; i < n; ++i){
			tree.push_back(new Node);
			cin >> tree[i] -> num;
		}
		for(ll i = 0; i < n-1; ++i){
			ll a,b;
			cin >> a >> b;
			tree[a-1] -> connections.push_back(tree[b-1]);
			tree[b-1] -> connections.push_back(tree[a-1]);
		}
		dfs(tree[0]);
		for(Node* node : tree){
			if(node -> ans){
				cout << "Yes\n";
			}else{
				cout << "No\n";
			}
		}
	}
}
