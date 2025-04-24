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

ll low(string l) {
	ll ans = 0;
	int digits = l.length();
	int fd = l[0] - '0';
	for (int i = fd; i < 10; i++) {
		if (i == fd) {

		} else {
			ll prod = 1;
			for (int j = digits - 1; j > 0; j--) {
				prod *= i;
			}
			ans += prod;
		}
	}
	return ans;
}

ll high(string h) {
	ll ans = 0;
	return ans;
}

ll mid(int digits, int fd) {
	ll ans = 0;
	for (int i = fd; i < 10; i++) {
		ll prod = 1;
		for (int j = digits - 1; j > 0; j--) {
			prod *= i;
		}
		ans += prod;
	}
	return ans;
}
 
void solve()
{
	string l, r;
	cin >> l >> r;
	// find the answer for each digit
	ll ans = 0;
	ans += low(l);
	ans += high(h);
	for (int digits = l.length() + 1; digits < r.length(); digits++) {
		ans += mid(digits, 1);
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