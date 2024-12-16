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

int fun(vector<ll> &arr, ll ans)
{
	int n = arr.size();
	ll last = 1e9;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] <= ans)
		{
			if (arr[i] <= last)
				last = arr[i];
			else
				return 1;
		}
	}
	last = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > ans)
		{
			if (arr[i] >= last)
				last = arr[i];
			else
				return 2;
		}
	}
	for (int i = 1; i < n; i++)
	{
		ll prev = abs(arr[i- 1] - ans);
		ll cur = abs(arr[i] - ans);
		if(cur < prev)
		{	
			if(arr[i - 1] <= ans && arr[i] > ans)
				return 1;
			else
				return 2;
		}
	}
	return 0;
}


void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	if (is_sorted(arr.begin(), arr.end()))
		return void(cout << "0");
	ll low = 0, high = 1e9;
	ll ans = -1;
	while (low <= high)
	{
		ll mid = low + (high - low) / 2LL;
		//<= in mid
		//> in mid
		ll last = 1e9;
		int cs = fun(arr, mid);
		if (cs == 1)
			high = mid - 1;
		else if (cs == 2)
			low = mid + 1;
		else
		{
			ans = mid;
			break;
		}
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