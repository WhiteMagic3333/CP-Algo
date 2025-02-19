#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
	int n, m;
	cin >> n >> m;
	vector<vector<int>> grid(n, vector<int> (m));
	for (auto &row : grid) {
		for (auto &e : row) {
			cin >> e;
		}
	}
	set<int> s1, s2;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i + j) % 2) {
				s1.insert(grid[i][j]);
			} else {
				s2.insert(grid[i][j]);
			}
		}
	}
	if ((s1.size() + s2.size()) == 1) {
		return void(cout << "0");
	}
	int ans = s1.size() + s2.size();
	for (auto i : s1) {
		int cnt = s1.size() - 1;
		if (s2.find(i) != s2.end()) {
			cnt += s2.size() - 1;
		} else {
			cnt += s2.size();
		}
		ans = min(ans, cnt);
	}
	for (auto i : s2) {
		int cnt = s2.size() - 1;
		if (s1.find(i) != s1.end()) {
			cnt += s1.size() - 1;
		} else {
			cnt += s1.size();
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}