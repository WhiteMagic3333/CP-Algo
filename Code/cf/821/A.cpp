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
	int n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	for (int i = 0; i + k - 1 < n; i++)
	{
		ll sum = 0;
		for (int j = 0; j < k; j++)
		{
			ll cur = 0;
			for (int p = i + j; p >= 0; p -= k)
				cur = max(arr[p], cur);
			for (int p = i + j; p < n; p += k){
				if(p > (i + k - 1))
				cur = max(arr[p], cur);
			}
			sum += cur;
		}
		ans = max(ans, sum);
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