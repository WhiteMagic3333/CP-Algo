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

ll find_old(vector<vector<vector<ll>>> &dp, int i, int j, int k, ll cur)
{
	ll old;
	old = (dp[i][j - 1][k] + cur) % mod;
	return old;
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>> (n + 1, vector<ll> (n + 1, 0)));
	/*
	dp[i][j][k] -> till the i'th index in arrays a and b, the numbers of pairs of subarrays
	such that the last element in a is ''atmost'' j and ''atmost'' k in b;
	*/
	for (int j = 1; j <= n; j++)
	{
		ll cur = 0;
		for (int k = j; k <= n; k++)
		{
			ll old = find_old(dp, 1, j, k, cur);
			dp[1][j][k] = (1 + old) % mod;
			cur = (cur + dp[1][j][k] - old) % mod;
		}
	}

	for (int i = 2; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ll cur = 0;
			for (int k = j; k <= n; k++)
			{
				ll old = find_old(dp, i, j, k, cur);
				ll add = 0;
				if (k != j)
					add = (add + dp[i - 1][j][n] - dp[i - 1][j][k - 1] + mod) % mod;
				else
					add = (add + dp[i - 1][j][n] - dp[i - 1][j - 1][k - 1] + mod) % mod;
				dp[i][j][k] = (add + old) % mod;
				cur = (cur + dp[i][j][k] - old) % mod;
			}
		}
	}

	// for (int j = 1; j <= n; j++)
	// {
	// 	for (int k = 1; k <= n; k++)
	// 		cout << dp[1][j][k] << " ";
	// 	cout << "\n";
	// }
	cout << dp[m][n][n];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}