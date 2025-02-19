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
	int n;
	cin >> n;
	string str;
	cin >> str;
	//left(i) == make all 1's till now to this pos
	//right(i) == make all 1's suffix till now to this pos

	vector<ll> left(n, 0), right(n + 1, 0);
	ll ones = str[0] == '1';
	for (int i = 1; i < n; i++) {
		if (str[i] == '1') {
			ones++;
		} else {
			left[i] += ones;
		}
		left[i] += left[i - 1];
	}
	ones = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (str[i] == '1') {
			ones++;
		} else {
			right[i] += ones;
		}
		right[i] += right[i + 1];
	}
	ll ans = right[0];
	for (int i = 1; i < n; i++) {
		ans = min({ans, left[i] + right[i + 1], left[i - 1] + right[i]});
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