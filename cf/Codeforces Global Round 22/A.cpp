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

ll fun(vector<ll> a, vector<ll> b)
{
	int n = a.size(), m = b.size();
	ll cur = 0;
	int i = 0, j = 0;
	if (a.size() == 0 || b.size() == 0)
	{
		while (i < n)
			cur += a[i++];
		while (j < m)
			cur += b[j++];
		return cur;
	}
	cur += b[m - 1];
	b.pop_back();
	m = b.size();
	i = 0, j = 0;
	while (1)
	{
		if ((i + j) % 2 == 0)
		{
			if (i == n)
				break;
			cur += 2LL * a[i];
			i++;
		}
		else {
			if (j == m)
				break;
			cur += 2LL * b[j];
			j++;
		}
	}
	while (i < n)
		cur += a[i++];
	while (j < m)
		cur += b[j++];
	return cur;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> type(n), a, b;
	cin >> type;
	for (int i = 0; i < n; i++)
	{
		ll p;
		cin >> p;
		if (type[i])
			a.push_back(p);
		else
			b.push_back(p);
	}
	sort(a.begin(), a.end(), greater<ll> ());
	sort(b.begin(), b.end(), greater<ll> ());
	ll ans = max(fun(a, b), fun(b, a));
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