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
	ll n, x, y;
	cin >> n >> x >> y;
	string a, b;
	cin >> a >> b;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] != b[i])
			count++;
	}
	if (count % 2)
		return void(cout << "-1");
	if (x >= y)
	{
		bool deadlock = false;
		for (int i = 1; i < n; i++)
		{
			if (a[i] != b[i] && a[i - 1] != b[i - 1])
				deadlock = true;
		}
		if (count == 2 && deadlock)
			return void(cout << min(x, 2LL * y));
		cout << (count / 2LL) * y;
	}
	else if (x < y)
	{
		ll ans = 0;
		ll evens = 0;
		for (int i = 1; i < n; i++)
		{
			if (a[i] != b[i] && a[i - 1] != b[i - 1]) {
				a[i] = b[i];
				a[i - 1] = b[i - 1];
				evens++;
				i++;
			}
		}
		ll rem = count - (evens * 2);
		ans = evens * x;
		cout << ans;
	}
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