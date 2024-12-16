#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
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
	ll p, q;
	cin >> p >> q;
	if (p % q)
		return void(cout << p);
	map<ll, ll> prime_factors;
	ll div = q;
	for (int i = 2; i < 1e5 + 1; i++)
	{
		while (div % i == 0) {
			div = div / i;
			prime_factors[i]++;
		}
	}
	if (div > 1) {
		prime_factors[div]++;
	}
	div = p / q;
	set<ll> s;
	for (auto &i : prime_factors)
	{
		ll cur = i.first;
		ll ins = i.first;
		while(div % cur == 0)
		{
			div = div / cur;
			ins = ins * cur;
		}
		s.insert(ins);
	}
	ll divide = (*s.begin());
	cout << p / divide;
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