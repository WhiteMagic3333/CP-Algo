#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;

ll mod = 998244353;
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


vector<ll> fac(60 + 1), inv_fac(60 + 1);

ll binpow(ll a, ll b, ll m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}


void pre()
{
	fac[0] = inv_fac[0] = 1;
	for (ll i = 1; i <= 60; i++)
	{
		fac[i] = (i * fac[i - 1]) % mod;
	}
	inv_fac[60] = binpow(fac[60], mod - 2, mod);
	for (ll i = 60; i > 1; i--)
	{
		inv_fac[i - 1] = (i * inv_fac[i]) % mod;
	}
}

ll C(ll a, ll b)
{
	return (((fac[a] * inv_fac[b]) % mod) * inv_fac[a - b]) % mod;
}

void solve()
{
	ll n;
	cin >> n;
	ll total = C(n, n / 2);
	ll draw = 1;
	ll boris = 0;
	ll alice = C(n - 1, (n - 1) / 2);
	for (ll all = n - 5; all > 0; all -= 4)
	{
		ll inside = all / 2;
		alice = (alice + 2 * C(all, inside)) % mod;
		if (inside)
			alice = (alice + C(all, inside - 1)) % mod;
	}
	boris = (total - draw - alice + mod + mod) % mod;
	cout << alice << " " << boris << " " << draw;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}