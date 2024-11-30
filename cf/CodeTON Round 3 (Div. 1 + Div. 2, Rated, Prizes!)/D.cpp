#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<set>
using namespace std;
typedef long long ll;
#define mod 998244353
vector<bool> prime;
vector<ll> primes;
void sieve(ll n)
{
	prime.resize(n + 1, true);
	prime[0] = prime[1] = false;
	for (ll i = 2; i <= n; i++) {
		if (prime[i]) {
			primes.push_back(i);
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

ll fun(set<ll> &s, ll &n)
{
	vector<ll> arr;
	for (int i : s)
		arr.push_back(i);
	ll k = arr.size();
	ll ans = 0, num, cnt;
	//subset dp/mask
	for (int i = 1; i < (1 << k); i++)
	{
		num = n, cnt = 0;
		for (int j = 0; (1 << j) <= i; j++)
		{
			if ((1 << j)&i) {
				cnt++;
				num /= arr[j];
			}
		}
		if (cnt % 2)
			ans += num;
		else
			ans -= num;
	}
	return ans % mod;
}

void print(set<ll> &m)
{
	for (ll i : m)
		cout << i << " ";
	cout << '\n';
}

void print(vector<ll> &m)
{
	for (ll i : m)
		cout << i << " ";
	cout << '\n';
}

void solve()
{
	int n, m;
	cin >> n >> m;
	vector<ll> arr(n);
	cin >> arr;
	vector<ll> prime_factors;
	ll cur = arr[0];
	for (int i = 0; i < primes.size(); i++)
	{
		while (cur % primes[i] == 0) {
			prime_factors.push_back(primes[i]);
			cur = cur / primes[i];
		}
	}
	prime_factors.push_back(cur);
	ll ans = 1;
	for (int i = 1; i < n; i++)
	{
		ll count = m / arr[i];
		cur = arr[i];
		vector<ll> common;
		for (auto j : prime_factors)
		{
			if (cur % j == 0)
			{
				cur = cur / j;
				common.push_back(j);
			}
		}
		if (cur != 1)
			return void(cout << '0');

		for (auto j : common)
		{
			auto p = find(prime_factors.begin(), prime_factors.end(), j);
			prime_factors.erase(p);
		}

		// cout << common;
		// print(prime_factors);

		set<ll> prime_factors_distinct;
		for (auto j : prime_factors)
			prime_factors_distinct.insert(j);
		count = (count - fun(prime_factors_distinct, count) + mod) % mod;
		ans = (ans * count) % mod;
		prime_factors.erase(prime_factors.begin(), prime_factors.end());
		while (common.size())
		{
			prime_factors.push_back(common.back());
			common.pop_back();
		}
		// cout << ans << " ";
	}
	cout << ans;
}
//
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	sieve(4e4);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}
	return 0;
}