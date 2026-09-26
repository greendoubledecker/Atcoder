//store prefix sum of drink costs drink[] where the value is pair<K dollar bills paid, change recieved>
//store prefix sum of food costs food[] where value is the cost
//binary search on answer
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,m,k,x,y;
bool check(vector<pair<ll, ll>> drink, vector<ll> food, ll test){
	//cout << "testing " << test << endl;
	for(ll i = 0; i <= test; ++i){ //number of drinks
		if(test - i > n) continue;
		if(i > m) break;
		//cout << i << " drinks\n";
		if(drink[i].first <= y){
			//cout << "in\n";
			//cout << "drink cost: " << drink[i].first << "*k - " << drink[i].second;
			//cout << " food cost: " << food[test-i] << endl;
			ll totalcost = drink[i].first*k - drink[i].second + food[test - i]; //if totalcost is payable, then the dessert can be exactly paid and the drinks will not get over Y K dollar bills
			if(totalcost <= k*y + x) return true;
		}else return false; //first will only get higher
	}
	return false;
}
int main(){
	cin >> n >> m >> k >> x >> y;
	vector<ll> food;
	food.push_back(0);
	vector<ll> foodsort;
	for(ll i = 0; i < n; ++i){
		ll a; cin >> a;
		foodsort.push_back(a);
	}
	sort(foodsort.begin(), foodsort.end());
	for(ll i = 0; i < n; ++i){
		ll a = foodsort[i];
		food.push_back(food[food.size()-1] + a);
		//cout << "Food: " << food[food.size()-1] << endl;
	}
	vector<pair<ll, ll>> drink;
	drink.push_back({0,0});
	vector<ll> drinksort;
	for(ll i = 0; i < m; ++i){
		ll b; cin >> b;
		drinksort.push_back(b);
	}
	sort(drinksort.begin(), drinksort.end());
	for(ll i = 0; i < m; ++i){
		ll b = drinksort[i];
		ll kUsed = (b+k-1)/k;
		ll change = kUsed * k - b;
		drink.push_back({drink[drink.size()-1].first + kUsed, drink[drink.size()-1].second + change});
		//cout << "Drink: " << drink[drink.size()-1].first << ' ' << drink[drink.size()-1].second << endl;
	}
	//cout << "blah\n";
	ll l = 0, r = n+m, ans = -1;
	while(l <= r){
		ll mid = l + (r-l)/2;
		if(check(drink, food, mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << ans << endl;
}
/*5 5 10
23 12
12 13 14 23 19
12 17 14 19 22
*/
