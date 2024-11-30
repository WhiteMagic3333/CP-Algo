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

vector<ll> p(1e5 + 1);

void pre() 
{
	p[0] = 1LL;
	for (int i = 1; i < 1e5 + 1; i++)
	{
		p[i] = (p[i - 1] + p[i - 1]) % mod;
	}
}


void solve()
{
	int n, k;
	cin >> n >> k;
	k = min(k, n);
	ll index = 2;
	ll ans = (p[n - 1] + 1) % mod;
	for (int i = 1; i < k; i++)
	{
		ans = (ans + p[n - i - 1]) % mod;
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	solve();
	return 0;
}