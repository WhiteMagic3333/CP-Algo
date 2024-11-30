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

void update(char ch, ll &lsum, ll &rsum)
{
	if (ch == 'L')
		lsum--;
	else if (ch == 'R')
		lsum++;
	else if (ch == 'U')
		rsum--;
	else
		rsum++;
}

void solve()
{
	ll n;
	cin >> n;
	string str;
	cin >> str;
	str = " " + str;
	ll ans = 1e10;
	bool f = true;
	map<array<ll, 2>, ll> m;
	m[ {0, 0}] = 1;
	ll lsum = 0, rsum = 0;
	ll left = -1, right = -1;
	for (int i = 1; i <= n; i++)
	{
		update(str[i], lsum, rsum);
		ll found = m[{lsum, rsum}];
		if (found)
		{
			if (ans > (i - found + 1))
			{
				ans = i - found + 1;
				left = found;
				right = i;
			}
			f = false;
		}
		m[ {lsum, rsum}] = i + 1;
	}
	if (f)
		cout << "-1";
	else
		cout << left << " " << right;
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