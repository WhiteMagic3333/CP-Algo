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
	int n;
	cin >> n;
	ll a = 1, b = n * n;
	vector<vector<ll>> grid(n, vector<ll> (n, 0));
	int cur = 0;
	for (int i = 0; i < n; i++)
	{
		if (i % 2)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (cur)
					grid[i][j] = b--;
				else
					grid[i][j] = a++;
				cur = cur ^ 1;
			}
		}
		else
		{
			for (int j = 0; j < n; j++)
			{
				if (cur)
					grid[i][j] = b--;
				else
					grid[i][j] = a++;
				cur = cur ^ 1;
			}
		}
		cout << grid[i];
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