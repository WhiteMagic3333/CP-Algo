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
	ll n, a, b, k;
	cin >> n >> a >> b >> k;
	vector<ll> arr(n);
	cin >> arr;
	ll ans = 0;
	multiset<ll> req;
	ll need;
	for (int i = 0; i < n; i++)
	{
		ll q = arr[i] / (a + b) - ((arr[i] % (a + b) ? 0 : 1));
		ll cur = q * (a + b);
		ll rest = arr[i] - cur - a;
		if (rest > 0)
		{
			need = rest / a + (rest % a ? 1 : 0);
			req.insert(need);
			// cout << need << " ";
		}
		else{
			// cout << "0 ";
			ans++;
		}
	}
	for (auto i : req)
	{
		if (i <= k)
		{
			ans++;
			k = k - i;
		}
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}