#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#define debug(x) cout << #x << " is " << x << endl;
#define debugVec(x) cout << #x << ": "; for(auto moo : x) cout << moo << ' '; cout << endl;
#define debug2d(x) cout << #x << ":\n"; for(auto moo : x){for(auto mooo : moo) cout << mooo << ' ';cout << endl;}
#define printLocal(x) cout << x << endl;
#else
#define debug(x)
#define debugVec(x)
#define debug2d(x)
#define printLocal(x)
#endif
int main(){
	ll n,m;
	cin >> n >> m;
	vector<set<pair<ll, ll>>> edges(n);
	for(ll i = 0; i < m; ++i){
		ll a,b,c;
		cin >> a >> b >> c;
		edges[a-1].insert({b-1, c});
	}
	vector<ll> shortest(n, 1e18), lastcol(n), second(n, 1e18);
	queue<array<ll,3>> q;
	q.push({0,-1,0});
	shortest[0] = 0;
	while(!q.empty()){
		auto [cur, col, dist] = q.front();
		q.pop();
		for(auto [next, c] : edges[cur]){
			if(c == col) continue;
			if(shortest[next] == 1e18){
				shortest[next] = dist + 1;
				lastcol[next] = c;
				q.push({next, c, dist+1});
			}else if(second[next] == 1e18 && lastcol[next] != c){
				second[next] = dist + 1;
				q.push({next, c, dist+1});
			}
		}
	}
	if(shortest[n-1] >= 1e18){
		cout << "-1\n";
		return 0;
	}
	cout << shortest[n-1] << endl;
}
