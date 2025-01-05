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

ll calc(ll a, ll b, ll c) {
	return (a ^ b) + (b ^ c) + (c ^ a);
}
 
void solve()
{
	ll l, r;
	cin >> l >> r;
	ll ans = 0;
	vector<int> answer(3, 0);
	for (int i = l; i <= r - 2; i++) {
		for (int j = i + 1; j <= r - 1; j++) {
			for (int k = j + 1; k <= r; k++) {
				if (calc(i, j, k) > ans) {
					answer = {i, j, k};
					ans = calc(i, j, k);
				}
			}
		}
	}
	cout << ans;
	// cout << l << " " << r;
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