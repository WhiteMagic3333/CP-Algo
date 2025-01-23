#include <algorithm>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 998244353
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

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll modInverse(ll A, ll M) {
	return binpow(A, M - 2, M) % M;
}

void solve()
{
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n), b(n);
	cin >> a >> b;
	auto c = a;
	auto d = b;
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	ll ans = 1;
	for (int i = 0; i < n; i++) {
		ans *= min(c[i], d[i]);
		ans %= mod;
	}
	cout << ans << " ";
	while (q--) {
		ll ch, x;
		cin >> ch >> x;
		x--;
		if (ch == 1) {
			a[x]++;
			int p = lower_bound(c.begin(), c.end(), a[x]) - c.begin() - 1;
			c[p]++;
			if (c[p] <= d[p]) {
				ll inv = modInverse(c[p] - 1, mod);
				ans *= inv;
				ans %= mod;
				ans *= a[x];
				ans %= mod;
			}
		} else {
			b[x]++;
			int p = lower_bound(d.begin(), d.end(), b[x]) - d.begin() - 1;
			d[p]++;
			if (d[p] <= c[p]) {
				ll inv = modInverse(d[p] - 1, mod);
				ans *= inv;
				ans %= mod;
				ans *= b[x];
				ans %= mod;
			}
		}
		cout << ans << " ";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while(t--) {
		solve();
		cout << "\n";
	}
 
	return 0;
}