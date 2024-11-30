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
	char ch;
	cin >> ch;
	vector<int> r, y, g;
	for (int i = 0; i < n; i++)
	{
		char cur;
		cin >> cur;
		if (cur == 'r')
			r.push_back(i);
		else if (cur == 'y')
			y.push_back(i);
		else
			g.push_back(i);
	}
	g.push_back(n + g[0]);
	if (ch == 'g')
		return void(cout << "0");
	int mx = 0;
	if (ch == 'r')
	{
		for (int i = 0; i < r.size(); i++)
		{
			int cur = *(upper_bound(g.begin(), g.end(), r[i])) - r[i];
			mx = max(mx, cur);
		}
	}
	else
	{
		for (int i = 0; i < y.size(); i++)
		{
			int cur = *(upper_bound(g.begin(), g.end(), y[i])) - y[i];
			mx = max(mx, cur);
		}
	}
	cout << mx;
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