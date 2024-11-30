#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<list>
using namespace std;
typedef long long ll;
#define mod 998244353
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
	ll n, m, k, q;
	cin >> n >> m >> k >> q;
	ll cnt = 0;
	list<array<ll, 4>> stored;
	vector<bool> rows(n + 1, false);
	vector<bool> columns(m + 1, false);
	while (q--)
	{
		ll x, y;
		cin >> x >> y;
		stored.push_back({x, y, 0, 0});
	}
	if (min(n, m) == 1)
		return void(cout << k);
	auto it = stored.end();
	ll rows_filled = 0, columns_filled = 0;
	do {
		it--;
		ll x = (*it)[0];
		ll y = (*it)[1];
		(*it)[2] = rows_filled;
		(*it)[3] = columns_filled;
		bool flag = true;
		if (rows_filled == n || columns_filled == m || (rows[x] && columns[y]))
			flag = false;
		if (rows[x] == false)
		{
			rows_filled++;
			rows[x] = true;
		}
		if (columns[y] == false)
		{
			columns_filled++;
			columns[y] = true;
		}
		if (flag)
			cnt++;
	} while (it != stored.begin());

	ll ans = 1;
	while (cnt--)
		ans = (ans * k) % mod;
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		solve();
		cout << "\n";
	}
	return 0;
}