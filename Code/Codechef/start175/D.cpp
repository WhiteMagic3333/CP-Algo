#include <algorithm>
#include <unordered_map>
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

ll freq(vector<ll> &idx, int low, int high) {
	auto it1 = lower_bound(idx.begin(), idx.end(), low);
	auto it2 = upper_bound(idx.begin(), idx.end(), high);
	return (long long)(it2 - it1);
}
 
void solve()
{
	ll n, x;
	cin >> n >> x;
	vector<ll> arr(n);
	cin >> arr;
	unordered_map<ll, vector<ll>> tar;
	for (int i = 0; i < n; i++) {
		tar[arr[i]].push_back(i);
	}
	ll low = 0, high = 0, ans = 0;
	for (auto &[val, idx] : tar) {
		ll f = (long long)idx.size();
		ans = max(ans, f);
		if (x != 1 && val % x == 0 && tar.count(val / x)) {
			ll low = -1;
			for (auto i : idx) {
				high = i;
				ans = max(ans, f + freq(tar[val / x], low, high));
				low = i;
			}
			high = n;
			ans = max(ans, f + freq(tar[val / x], low, high));
		}
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