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

ll digits(ll a)
{
	ll d = 0;
	while (a)
	{
		d++;
		a = a / 10LL;
	}
	return d;
}

void solve()
{
	int n;
	cin >> n;
	multiset<int> a, b;
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		a.insert(e);
	}
	for (int i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		auto p = a.find(e);
		if (p == a.end()) {
			b.insert(e);
			continue;
		}
		a.erase(p);
	}
	ll ans = 0, ones = 0;
	multiset<int> c, d;
	for (auto p = a.begin(); p != a.end(); p++)
	{
		ll di = digits(*p);
		if (di == 1)
			di = *p;
		else
			ans++;
		c.insert(di);

	}
	for (auto p = b.begin(); p != b.end(); p++)
	{
		ll di = digits(*p);
		if (di == 1)
			di = *p;
		else
			ans++;
		if (c.find(di) == c.end())
			d.insert(di);
		else
			c.erase(c.find(di));
	}
	for (auto p = c.begin(), q = d.begin(); p != c.end(); p++, q++)
	{
		if ((*p) != 1)
			ans++;
		if ((*q) != 1)
			ans++;
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