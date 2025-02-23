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
	int n;
	cin >> n;
	vector<ll> h(n), dp(n + 5, 1e18);
	cin >> h;
	dp[0] = 0;
	for (int i = 0; i < n; i++){
		dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
		dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
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