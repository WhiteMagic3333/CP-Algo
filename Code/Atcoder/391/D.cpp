#include <algorithm>
#include <iostream>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
 
void sieve(ll n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i] && i * i <= n) {
			for (ll j = i * i; j <= n; j += i)
				prime[j] = false;
		}
	}
}
 
template<typename T>
std::istream& operator>>(std::istream&in, std::vector<T>& v) {
	for (T& x : v)
		in >> x;
	return in;
}
 
template<typename T>
std::ostream& operator<<(std::ostream&out, std::vector<T>& v) {
	for (const T& x : v)
		std::cout << x << ' ';
	std::cout << '\n';
	return out;
}

// ll exhaust(ll time, vector<vector<array<ll, 2>>> &col) {
// 	//max row = time
// 	ll ans = 1e9;
// 	for (int i = 1; i < col.size(); i++) {
// 		//get how many rows will come at time t
// 		// max row <= t
// 		array<ll, 2> s = {time + 1, 0};
// 		ll cur = lower_bound(col[i].begin(), col[i].end(), s) - col[i].begin();
// 		// cout << cur << "_" << col[i].size() << " ";
// 		ans = min(cur, ans);
// 	}
// 	return ans;
// }
 
void solve()
{
	int n, w;
	cin >> n >> w;
	vector<vector<array<ll, 2>>> col(w + 1);
	vector<ll> exhaust(n + 1, 0);
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		col[x].push_back({y, i + 1});
	}
	int q;
	cin >> q;
	vector<array<int, 2>> queries(q);
	for (auto &query : queries) {
		cin >> query[0] >> query[1];
	}
	for (int i = 1; i <= w; i++) {
		sort(col[i].begin(), col[i].end());
	}
	vector<int> row_count(n + 1, 0);
	for (int i = 1; i <= w; i++) {
		for (int j = 0; j < col[i].size(); j++) {
			if (j = 0)
			row_count[col[i][j][1]] = j + 1;
			exhaust[j] = max(exhaust[j], col[i][j][0]);
		}

	}
	for (auto &query : queries) {
		//get how many rows are exhausted at t
		//find the row count of i
		ll _row_count = row_count[query[1]];
		if (_row_count > exhaust[query[1]]) {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}