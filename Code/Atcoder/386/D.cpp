#include <algorithm>
#include <vector>
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
 
void solve()
{
	ll n, m;
	cin >> n >> m;
	vector<vector<int>> b, w;
	for (int i = 0; i < m; i++) {
		int x, y;
		char ch;
		cin >> x >> y >> ch;
		if (ch == 'B') {
			b.push_back({x, y});
		} else {
			w.push_back({x, y});
		}
	}
	sort(b.begin(), b.end());

	int mx = 0;
	for (int i = b.size() - 1; i >= 0; i--) {
		mx = max(mx, b[i][1]);
		b[i].push_back(mx);
	}

	for (auto &cur : w) {
		int r = cur[0], c = cur[1];
		vector<int> l = {r, 0, 0};
		auto lb = lower_bound(b.begin(), b.end(), l);
		if (lb != b.end()) {
			l = *lb;
			if (l[2] >= c) {
				cout << "No";
				return;
			}
		}
	}
	cout << "Yes";
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}