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
	int n;
	cin >> n;
	array<ll, 3> dp, cpy;
	ll a, b, c;
	cin >> a >> b >> c;
	dp[0] = a;
	dp[1] = b;
	dp[2] = c;
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		cpy[0] = a + max(dp[1], dp[2]);
		cpy[1] = b + max(dp[0], dp[2]);
		cpy[2] = c + max(dp[0], dp[1]);
		dp = cpy;
	}
	cout << max({dp[0], dp[1], dp[2]});
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}