#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	ll total = 0;
	ll yr = 0;
	while(total < k){
		total += yr + n;
		++yr;
	}
	cout << yr - 1 << endl;
}
