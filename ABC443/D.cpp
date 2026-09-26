#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector<ll> v(n);
		for(ll i = 0; i < n; ++i){
			cin >> v[i];
		}
		//cout << "recieved" << endl;
		vector<ll> lowPointsLeft;
		ll low = 1'000'000'000'000;
		for(ll i = 0; i < n; ++i){
			if(v[i] < low){
				lowPointsLeft.push_back(i);
				low = v[i];
			}
			++low;
		}
		
		vector<ll> lowPointsRight;
		low = 1'000'000'000'000;
		for(ll i = n - 1; i >= 0; --i){
			if(v[i] < low){
				lowPointsRight.push_back(i);
				low = v[i];
			}
			++low;
		}
		//cout << "calculated" << endl;
		reverse(lowPointsRight.begin(), lowPointsRight.end());
		vector<ll> lowPoints;
		set_intersection(lowPointsLeft.begin(), lowPointsLeft.end(), lowPointsRight.begin(), lowPointsRight.end(), back_inserter(lowPoints));
		if(lowPoints.size() == 0){
			cout << 0 << '\n';
			continue;
		}
		//cout << "here" << endl;
		vector<ll> end(n);
		ll right = lowPoints[0];
		ll left = -1;
		ll rind = 0;
		for(ll i = 0; i < n; ++i){
			if(i == right){
				end[i] = v[right];
				left = right;
				++rind;
				if(rind == lowPoints.size()){
					right = -1;
					continue;
				}
				right = lowPoints[rind];
				continue;
			}
			
			if(left == -1){
				end[i] = v[right] + (right - i);
			}else if(right == -1){
				end[i] = v[left] + (i - left);
			}else{
				end[i] = min(v[right] + (right - i), v[left] + (i - left));
			}
		}
		
		ll sum = 0;
		for(ll i = 0; i < n; ++i){
			//cout << "end: " << end[i] << endl;
			sum += v[i] - end[i];
		}
		cout << sum << '\n';
	}
}
