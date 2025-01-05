#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include<bitset>
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

int calc(int a, int b) {
	bitset<32> _a(a);
	bitset<32> _b(b);
	bitset<32> _c;
	// cout << _a << '\n' << _b << '\n';
	int in = 0;
	for (int i = 31; i >= 0; i--) {
		if (_a[i] != _b[i]) {
			_c[i] = 0;
			in = i;
			//two choices
			// take _c[i] = 0 and don't let it be smaller than a
			// or take _c[1] = 1 and don't let it be bigger than b
			break;
		} else {
			_c[i] = _a[i];
		}	
	}
	if (in != -1) {
		_c[in] = 1;
	}
	int c = 0;
	for (int i = 0; i < 32; i++) {
		c += (1 << i) * _c[i];
	}
	// cout << _c << '\n';
	return c;
}

ll sum(ll a, ll b, ll c) {
	return (a ^ b) + (b ^ c) + (c ^ a);
}
 
void solve()
{
	ll l, r;
	cin >> l >> r;
	// cout << r - 1 << " " << r - 2 << " " << r - 3;
	// 00 ^ 11 + 11 ^ 01 + 00 ^ 10 --> max this
	// 11 + 01 + 10
	// c = r - 2;
	// ll a, b, c;
	// cin >> a >> b >> c;
	// print(a ^ b);
	// print(b ^ c);
	// print(c ^ a);
	// a ^ b + b ^ c + c ^ a
	// 2 ones at each bit i.e 
	// so to get 2 ones at each bit
	// we can have 2, ones and 1 zero
	// or 1 one and 2 zeroes

	// try to maximize each bit
	// calc(l, r);
	cout << l << ' ' << calc(l, r) << ' ' <<  r;

	// so a = l, c = r
	// b = 

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