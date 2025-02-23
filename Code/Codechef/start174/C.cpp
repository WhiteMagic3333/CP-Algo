#include <algorithm>
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
	ll n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	unordered_map<ll, ll> m;
	for (auto cur : arr) {
		m[cur]++;
	}
	ll mx = *max_element(arr.begin(), arr.end());
	ll ans = mx + 1;
	for (ll i = 0; i <= n; i++) {
		ll c = mx - i;
		ll len = 0;
		if (c == 0) {
			break;
		}
		for (ll g = c; g <= mx; g += c) {
			if (m.count(g)) {
				len += m[g];
			}
		}
		ans = max(ans, c + len);
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