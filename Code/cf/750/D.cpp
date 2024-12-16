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

ll lcm(ll a, ll b)
{
	ll g = __gcd(a, b);
	ll _lcm = (a * b) / g;
	return _lcm;
}
ll sign(ll a)
{
	if (a < 0)
		return -1;
	return 1;
}
void solve()
{
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	if (n % 2 == 0)
	{
		for (int i = 1; i < n; i += 2)
		{
			ll l = lcm(abs(arr[i]), abs(arr[i - 1]));
			cout << l / abs(arr[i - 1]) * sign(arr[i - 1]) << " " << l /abs(arr[i]) * (-1) * sign(arr[i]) << " ";
		}
		return;
	}
	for (int i = 1; i < n - 3; i += 2)
	{
		ll l = lcm(abs(arr[i]), abs(arr[i - 1]));
		cout << l / abs(arr[i - 1]) * sign(arr[i - 1]) << " " << l / abs(arr[i]) * (-1) * sign(arr[i]) << " ";
	}
	ll sum = abs(arr[n - 3]) + abs(arr[n - 2]);
	ll l = lcm(sum, abs(arr[n - 1]));
	ll a = l / sum;
	ll b = l / abs(arr[n - 1]);
	cout << sign(arr[n - 3]) * a << " " << sign(arr[n - 2]) * a << " " << sign(arr[n - 1]) * b * (-1);
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