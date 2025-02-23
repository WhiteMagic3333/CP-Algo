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

//code snippet for 1d, 2d DP

ll fun(vector<ll> &dp, int i) {
	if (i >= 0) {
		return dp[i];
	}
	return 0;
}

 
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<ll> h(n + k + 1, 0), dp(n + k + 1, 1e18);
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		for (int j = 1; j <= k; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
		}
	}
	cout << dp[n - 1];
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}