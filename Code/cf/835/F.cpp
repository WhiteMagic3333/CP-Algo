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
	ll n, c, d;
	cin >> n >> c >> d;
	vector<ll> arr(n);
	cin >> arr;
	sort(arr.begin(), arr.end(), greater<ll> ());
	ll cur = 0;
	for (int i = 0; i < min(n, d); i++)
		cur += arr[i];
	if (cur >= c)
		return void(cout << "Infinity");
	if (arr[0] * d < c)
		return void(cout << "Impossible");
	ll low = 0, high = d - 2;
	ll ans = 0;
	while (low <= high)
	{
		ll k = low + (high - low) / 2LL;
		ll last = k + 1;
		cur = 0;
		for (int i = 0; i < min(last, n); i++)
		{
			cur += arr[i] + ((d - i - 1) / (k + 1)) * arr[i];
		}
		if (cur >= c)
		{
			ans = max(ans, k);
			low = k + 1;
		}
		else
			high = k - 1;

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