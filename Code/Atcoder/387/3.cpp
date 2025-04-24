#include <bitset>
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

long getMinimumCost(vector<int> &c, int mw) {
	int n = c.size();
	long ans = 0;
	vector<long> dp(32);
	dp[0] = c[0];
	for (int i = 1; i < 32; i++) {
		dp[i] = dp[i - 1] * 2;
		if (i < n) {
			dp[i] = min(c[i] * 1L, dp[i]);
		}
	}
	cout << dp;
	int bit = 0;
	while(mw) {
		if (mw % 2) {
			ans += dp[bit];
		} else {
			ans = min(ans, dp[bit]);
		}
		bit++;
		mw /= 2;
	}
	for (int i = bit; i < 32; i++) {
		ans = min(ans, dp[i]);
	}
	return ans;
}
 
void solve()
{
	ll n;
	cin >> n;
	vector<int> cost(n);
	ll mw;
	cin >> cost >> mw;
	cout << getMinimumCost(cost, mw);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}