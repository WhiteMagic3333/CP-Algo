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
	ll n, m;
	cin >> n >> m;
	string str;
	cin >> str;
	ll ans = 0;
	vector<ll> vertical(m + 1, 0), horizontal(m + 1, 0);
	ll last = - n * m;
	for (int i = 0; i < n * m; i++)
	{
		if (str[i] == '1') {
			vertical[i % m]++;
			if (vertical[i % m] == 1) {
				ans++;
			}
			last = i;
		}
		if(i - last < m)
			horizontal[i % m]++;
		cout << ans + horizontal[i%m] << " ";
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