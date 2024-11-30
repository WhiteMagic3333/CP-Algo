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
	ll a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a == 0)
		return void(cout << "1");
	ll ans = a;
	ll rem = min(b, c);
	b = b - rem;
	c = c - rem;
	ans = ans + rem + rem;
	a++;
	ll bc = max(b, c);
	rem = min(bc, d);
	rem = min(rem, a);
	a -= rem;
	ans += rem;
	if (a > 0) {
		if (rem == bc)
			bc = 0;
		else
			d = 0;
		ans += min(a, max(bc, d));
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