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

ll fun(vector<ll> &arr, ll k)
{
	ll diff = 0;
	for (int i = 1; i < arr.size(); i++)
	{
		ll cur = (arr[i] == -1 ? k : arr[i]);
		ll prev = (arr[i - 1] == -1 ? k : arr[i - 1]);
		diff = max(diff, abs(cur - prev));
	}
	return diff;
}

void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	ll value = fun(arr, 0);
	ll low = 0, high = 1e9;
	while (low <= high)
	{
		ll mid = low + (high - low) / 2;
		ll cur = fun(arr, mid);
		ll next = fun(arr, mid + 1);
		if (mid <= 1e9)
		{
			if (cur < value)
			{
				value = cur;
				ans = mid;
			}
		}
		if (cur >= next)
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << value << "  " << ans;

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
		cout << "\n";
	}
	return 0;
}