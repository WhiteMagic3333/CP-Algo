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

int digits(ll a)
{
	int d = 0;
	while (a)
	{
		d++;
		a = a / 10;
	}
	return d;
}

ll power(ll n)
{
	ll cur = 1;
	while(n--)
		cur = cur * 10;
	return cur;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	ll temp_n = n, temp_m = m;
	vector<int> a(2, 0);
	while (n % 2 == 0)
	{
		a[0]++;
		n = n / 2;
	}
	while (n % 5 == 0)
	{
		a[1]++;
		n = n / 5;
	}
	ll ans = temp_n;
	ll cur = 1;
	if (a[0] > a[1]) // more two's
	{
		while (cur * 5 <= m && a[0] > a[1])
		{
			cur = cur * 5;
			a[1]++;
		}
	}
	else if (a[1] > a[0]) // more fives
	{
		while (cur * 2 <= m && a[0] < a[1])
		{
			cur = cur * 2;
			a[0]++;
		}
	}
	cur = cur * power(digits(m / cur) - 1);
	ll mx = (m / cur) * cur;
	ans = ans * mx;
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