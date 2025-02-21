#include <vector>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
vector<bool> prime;
ll mod = 998244353;

 
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

ll _dp(vector<ll> &dp, int i) {
	if (i < 0) {
		return 0LL;
	}
	return dp[i];
}
 
void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	vector<ll> dp(3, 0);
	for (int i = 0; i < n; i++) {
		dp[0] += arr[i] == 1;
		dp[0] %= mod;

		if (arr[i] == 2) {
			ll old = dp[1];
			dp[1] += _dp(dp, 0);
			dp[1] %= mod;
			dp[1] += old;
			dp[1] %= mod;
		}

		dp[2] += (arr[i] == 3) ? _dp(dp, 1) : 0;
		dp[2] %= mod;
	}
	cout << dp[2];
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