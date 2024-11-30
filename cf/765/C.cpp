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
	int n, l, k;
	cin >> n >> l >> k;
	vector<ll> signs(n), time(n);
	cin >> signs >> time;
	vector<vector<ll>> dp(n + 1, vector<ll> (n + 1, 1e18));
	signs.push_back(l);
	ll prev;
	for (int i = 0; i <= n ; i++)
		dp[n][i] = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = 0; j <= k; j++)
		{
			ll cur = 1e18;
			for (int p = 0; p <= j && (i + p + 1) <= n; p++)
			{
				cur = min(cur, (signs[i + p + 1] - signs[i]) * time[i] + dp[i + p + 1][j - p]);
			}
			dp[i][j] = cur;
			
		}
	}
	cout << dp[0][k];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}