#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef int64_t ll;
vector<bool> prime;
ll mod = 998244353;

void sieve(ll n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i] && i * i <= n) {
			for (ll j = 2 * i; j <= n; j += i)
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
	ll n, m;
	cin >> n >> m;
	sieve(n);
	ll final_ans = 0;
	ll l = 1, p;
	ll sub = m % mod;
	ll total = m % mod;
	for (ll i = 2; i <= n; i++)
	{
		if (prime[i])
			l = (l * i);
		if (l > m){
			sub = 0;
			l = 0;
		}
		if (sub)
			p = (m / l) % mod;
		sub = (sub * p) % mod;
		total = (total * (m % mod)) % mod;
		ll eligible = (total - sub + mod) % mod;
		final_ans = (final_ans + eligible) % mod;
		
	}
	cout << final_ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	solve();
	return 0;
}