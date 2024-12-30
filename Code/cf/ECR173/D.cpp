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
	// issue
	// I asked in my mind that what should be the
	// maximum gap between, two primes
	// what I should have asked
	// Maximum gap between two co primes

	ll l, r, h;
	cin >> l >> r >> h;
	ll low = (l + h - 1) / h;
	ll high = r / h;
	if (low > high) {
		return void(cout << "-1 -1");
	} else if (low == high) {
		if (low != 1) {
			return void(cout << "-1 -1");
		} else {
			return void(cout << h << " " << h);
		}
	} else {
		for (ll d = (high - low); d >= 0; d--) {
			for (ll k = low; k + d <= high; k++) {
				ll l1 = k;
				ll l2 = k + d;
				if (__gcd(l1, l2) == 1) {
					return void (cout << l1 * h << " " << l2 * h);
				}
			}
		}
	}
	return void(cout << "-1 -1");
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