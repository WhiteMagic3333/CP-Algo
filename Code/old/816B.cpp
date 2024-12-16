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
	ll n, k, b, s;
	cin >> n >> k >> b >> s;
	ll mn = max(0LL, (s - (n - 1) * max(1LL, k - 1)) / k);
	ll mx = s / k;
	if(b < mn || b > mx)
		return void(cout << "-1\n");
	vector<ll> ans(n);
	ans[0] = b * k;
	ll rem = s - b * k;
	for (int i = 0; i < n; i++)
	{
		ll remove = min(k - 1, rem);
		rem -= remove;
		ans[i] += remove;
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
	}
	return 0;
}