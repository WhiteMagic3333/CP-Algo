#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <queue>
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

ll n, m, x;

void rec(vector<vector<int>> &dir, vector<vector<int>> &rev, int i, vector<bool> &vis, vector<vector<ll>> &dp) {
	if (dp[i][0] < 1e18 && dp[i][1] < 1e18) {
		return;
	}
	vis[i] = true;
	for (auto &u : dir[i]) {
		if (!vis[u]) {
			rec(dir, rev, u, vis, dp);
			dp[i][0] = min(dp[i][0], 1LL + dp[u][0]);
			dp[i][0] = min(dp[i][0], 1LL + x + dp[u][1]);
			dp[i][1] = min(dp[i][1], 1LL + x + dp[u][0]);
			dp[i][1] = min(dp[i][1], 1LL + x + x + dp[u][1]);
		}
	}
	for (auto &u : rev[i]) {
		if (!vis[u]) {
			rec(dir, rev, u, vis, dp);
			dp[i][1] = min(dp[i][1], 1LL + dp[u][1]);
			dp[i][1] = min(dp[i][1], 1LL + x + dp[u][0]);
			dp[i][0] = min(dp[i][0], 1LL + x + dp[u][1]);
			dp[i][0] = min(dp[i][0], 1LL + x + x + dp[u][0]);
		}
	}
	vis[i] = false;
}

 
void solve()
{
	cin >> n >> m >> x;
	vector<vector<int>> dir(n + 1), rev(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		dir[u].push_back(v);
		rev[v].push_back(u); //opposite dir
	}
	vector<bool> vis(n + 1, false);
	vector<vector<ll>> dp(n + 1, vector<ll> (2, 1e18));
	dp[n][0] = dp[n][1] = 0;
	rec(dir, rev, 1, vis, dp);
	cout << min(dp[1][0], dp[1][1]);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}