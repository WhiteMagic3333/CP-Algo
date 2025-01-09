#include <sys/types.h>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef u_int64_t ll;
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

ll pow(ll a, ll b) {
	ll ans = 1;
	while(b--) {
		ans *= a;
	}
	return ans;
}

ll ways_digit(int digits, int fd, int ld) {//clarity
	ll ans = 0;
	for (int i = fd; i <= ld; i++) {
		ans += pow(i, digits - 1);
	}
	return ans;
}

ll dig(char ch) {
	return ch - '0';
}

ll ways(string x) {
	// cout << x << " ";
	//x is numN
	// no. of ways to get 0000 -> X
	int digits = x.length();
	ll ans = 0;
	//all numbers having lesser digits
	for (int d = 1; d < digits; d++) {
		ans += ways_digit(d, 1, 9);
	}
	ans += ways_digit(digits, 1, dig(x[0]) - 1);
	if (digits == 1) {
		ans++;
	}
	for (int i = 1; i < digits; i++) {
		ll xo = dig(x[0]);
		ll xi = dig(x[i]);
		ans += min(xi, xo) * pow(xo, digits - i - 1);
		// cout << min(xi, xo) * pow(xo, digits - i - 1) << " ";
		if (xi >= xo) {
			break;
		}
		if (i == digits - 1 && xi < xo) {
			ans++;
		}
	}

	return ans;
}
 
void solve()
{
	ll l, r;
	cin >> l >> r;
	l--;
	// find answer till l - 1
	// find answers till r
	// cout << ways(to_string(l)) << " ";
	// cout << ways(to_string(r));
	cout << ways(to_string(r)) - ways(to_string(l));
	// cout << ways_digit(2, 0, 1);
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}