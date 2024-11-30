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
	int n, q;
	cin >> n >> q;
	vector<vector<ll>> arr(1002, vector<ll> (1002, 0LL));
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b]++;
	}
	vector<vector<ll>> pre(1002, vector<ll> (1002, 0LL));
	for (ll i = 1000; i > 0; i--)
	{

		for (ll j = 1000; j > 0; j--)
		{
			pre[i][j] = (arr[i][j] * (i * j));
			pre[i][j] = pre[i][j] + pre[i][j + 1] + pre[i + 1][j] - pre[i + 1][j + 1];
		}
	}
	while (q--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cout << pre[a + 1][b + 1] - pre[a + 1][d] - pre[c][b + 1] + pre[c][d] << "\n";
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
	}
	return 0;
}