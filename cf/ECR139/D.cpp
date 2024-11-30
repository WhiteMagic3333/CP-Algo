#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;

vector<ll> lpf(1e7 + 1, 0);//largest prime factor of i

void sieve(ll n)
{
	prime.resize(n + 1, true);
	for (ll i = 2; i * i <= n; i++) {
		if (prime[i]) {
			lpf[i] = i;
			for (ll j = i * i; j <= n; j += i) {
				prime[j] = false;
				lpf[j] = i;
			}
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
	ll x, y;
	cin >> x >> y;
	ll diff = y - x;
	if (diff == 1)
		return void(cout << "-1");
	if (__gcd(x, y) != 1)
		return void(cout << "0");

	vector<ll> factors;
	while (diff != 1)
	{
		if (lpf[diff] == 0)
			lpf[diff] = diff;
		ll cur = lpf[diff];
		factors.push_back(cur);
		while (diff % cur == 0)
			diff /= cur;
	}

	ll ans = 1e9;
	for (int i = 0; i < factors.size(); i++)
	{
		ll next = (x / factors[i]) * factors[i];
		if (x % factors[i])
			next += factors[i];
		ans = min(ans, next - x);
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(1e7);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}