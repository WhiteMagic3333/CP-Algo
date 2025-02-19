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

int n, m;

vector<array<int, 2>> dxy = {
	{0, 1},
	{0, -1},
	{1, 0},
	{-1, 0},
};

bool check(int i, int j, vector<vector<int>> &grid) {
	for (auto d : dxy) {
		int dx = d[0] + i, dy = d[1] + j;
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[i][j] == grid[dx][dy]) {
			return true;
		}
	}
	return false;
}

 
void solve()
{
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
			if (check(i, j, grid)) {
				s2.insert(grid[i][j]);
			}
			s1.insert(grid[i][j]);
		}
	}
	int ans = 1e9;
	for (auto i : s1) {
		int cnt = s1.size() - 1;
		if (s2.find(i) != s2.end()) {
			cnt += max(0, (int)s2.size() - 1);
		} else {
			cnt += s2.size();
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