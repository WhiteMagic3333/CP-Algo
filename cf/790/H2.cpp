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

vector<ll> bit(2e5 + 1, 0);

ll sum (int i)// sum till i
{
	ll ans = 0;
	while (i)
	{
		ans += bit[i];
		i -= (i & (-i));
	}
	return ans;
}

void update(int i, ll x) // add x to element at index i
{
	while (i <= 2e5)
	{
		bit[i] += x;
		i += (i & (-i));
	}
}


void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n + 1);
	bit[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		bit[i] = 0;
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		ans += sum(n) - sum(arr[i] - 1);
		update(arr[i], 1);
	}
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