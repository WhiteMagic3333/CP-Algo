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

ll fun(vector<vector<ll>> &dp, vector<vector<bool>> &vis, vector<ll> &signs, vector<ll> &time, int i, int n, int k)
{
	if (i == n)
		return 0;
	if (vis[i][k])
		return dp[i][k];
	ll cur = 1e18;
	for (int j = 0; j + i + 1 <= n && j <= k; j++)
		cur = min(cur, (signs[i + j + 1] - signs[i]) * time[i] + fun(dp, vis, signs, time, i + j + 1, n, k - j));
	vis[i][k] = true;
	return dp[i][k] = cur;
}

void solve()
{
	int n, l, k;
	cin >> n >> l >> k;
	vector<ll> signs(n), per_km_time(n);
	cin >> signs >> per_km_time;
	vector<vector<ll>> dp(n + 1, vector<ll> (k + 1, 1e18));
	//dp[i][j] -> min time to reach end from position i with atmost j skips
	vector<vector<bool>> vis(n + 1, vector<bool> (k + 1, false));
	signs.push_back(l);
	cout << fun(dp, vis, signs, per_km_time, 0, n, k);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}