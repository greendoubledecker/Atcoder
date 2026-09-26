#include <bits/stdc++.h>
using namespace std;
using ll = long long;
string s;
vector<string> recurse(string cur){
	if(cur.size() == s.size()){
		return {cur};
	}else{
		ll equalind = -1;
		for(ll i = 0; i < cur.size(); ++i){
			if(s[cur.size()] == s[i]){
				equalind = i;
				break;
			}
		}
		if(equalind >= 0){
			cur.push_back(cur[equalind]);
			return recurse(cur);
		}else{
			vector<vector<string>> v;
			for(ll i = 0; i < 10; ++i){
				if(find(cur.begin(), cur.end(), i + '0') == cur.end()){
					//cout << "i = " << i << " works!\n";
					cur.push_back(i+'0');
					v.push_back(recurse(cur));
					cur.pop_back();
				}
			}
			vector<string> ans;
			for(vector<string> vec : v){
				for(string s : vec) ans.push_back(s);
			}
			return ans;
		}
	}
}
int main(){
	cin >> s;
	vector<string> v = recurse("");
	for(string s : v){
		//cout << "s: " << s << endl;
		ll num = stoll(s);
		if(num < pow(10, s.size()-1)) continue;
		bool flag = true;
		for(ll i = 2; i <= sqrt(num) + 1; ++i){
			if(!(num%i)){
				flag = false;
				break;
			}
		}
		if(flag){
			cout << num << endl;
			return 0;
		}
	}
	cout << "-1\n";
}
