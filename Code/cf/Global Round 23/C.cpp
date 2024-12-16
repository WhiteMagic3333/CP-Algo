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

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n), diff(n);
	cin >> arr;
	set<array<ll, 2>> s;
	for (int i = 1; i < n; i++)
	{
		diff[i] = min(0LL, arr[i] - arr[i - 1]);
		if (diff[i])
			s.insert({(-1) * diff[i], i});
	}
	ll cur = 0, index = -1;
	for (ll i = 1; i <= n; i++)
	{
		if (cur == 0)
		{
			if (s.size() == 0)
			{
				cout << n << " ";
				continue;
			}
			cur = (*s.begin())[0];
			index = (*s.begin())[1];
			s.erase(s.begin());
		}
		cur = max(0LL, cur - i);
		cout << index + 1 << " ";
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