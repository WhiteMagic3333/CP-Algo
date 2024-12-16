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
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll moves = 0;
	for (ll power = 1; (1LL << power) <= n; power++)
	{
		ll update = 1LL << power;
		ll half = update >> 1LL;
		for (ll j = update - 1; j < n; j += update)
		{
			if(abs(arr[j - half] - arr[j]) != half)
				return void(cout << "-1");
			if(arr[j - half] > arr[j])
			{
				moves++;
				swap(arr[j], arr[j - half]);
			}
		}
	}
	cout << moves;
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