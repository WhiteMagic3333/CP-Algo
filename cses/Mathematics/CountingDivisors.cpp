#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007
vector<bool> prime;
vector<ll> prime_fac;

void sieve(ll n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i] && i * i <= n) {
			prime_fac.push_back(i);
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
	ll x;
	cin >> x;
	if (x == 1)
		return void(cout << "1");
	ll ans = 1;
	for (int i = 0; i < prime_fac.size(); i++)
	{
		if (x % prime_fac[i] == 0)
		{
			ll cur = 0;
			while (x % prime_fac[i] == 0) {
				x = x / prime_fac[i];
				cur++;
			}
			ans = (ans * (cur + 1));
		}
	}
	if (x > 1)
		ans = ans * 2;
	cout << max(ans, 2LL);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(1e6);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}