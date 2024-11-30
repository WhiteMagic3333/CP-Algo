#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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
	multiset<array<ll, 3>> final;
	vector<ll> a(n), b(n);
	cin >> a >> b;
	for (int i = 0; i < n; i++)
	{
		final.insert({b[i] - a[i], a[i], b[i]});
	}
	ll ans = 0;
	while (final.size())
	{
		auto p = final.end();
		p--;
		ll cur = (*p)[0];
		final.erase(p);
		auto q = final.lower_bound({(-1) * cur, 0, 0});
		if (q == final.end())
			break;
		ll other = (*q)[0];
		if (cur + other >= 0)
			ans++;
		else
			break;
		final.erase(q);
	}
	cout << ans;
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