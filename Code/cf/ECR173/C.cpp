#include <valarray>
#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
#include <set>
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

void calc(int l, int r, vector<ll> &arr, set<ll> &ans, int sign) {
	// just to process all combinations from l to r in given sign
	if (l > r) {
		return;
	}
	//
	ll cur = 0, mx = 0;
	for (int i = l; i <= r; i++) {
		cur += (arr[i] * sign);
		cur = max(cur, 0LL);
		mx = max(mx, cur);
		ans.insert(mx * sign);
	}
}

ll left(int l, int r, vector<ll> &arr, int sign) {
	ll cur = 0, mx = 0;
	for (int i = r; i >= l; i--) {
		cur += (arr[i] * sign);
		mx = max(mx, cur);
	}
	return mx * sign;
}

ll right(int l, int r, vector<ll> &arr, int sign) {
	ll cur = 0, mx = 0;
	for (int i = l; i <= r; i++) {
		cur += (arr[i] * sign);
		mx = max(mx, cur);
	}
	return mx * sign;
}

 
void solve()
{
	int n;
	cin >> n;
	vector<ll> arr(n);
	cin >> arr;
	set<ll> ans;
	ans.insert(0);
	bool found = false;
	for (int i = 0; i < n; i++) {
		if (abs(arr[i]) != 1) {
			calc(0, i - 1, arr, ans, 1);
			calc(0, i - 1, arr, ans, -1);
			calc(i + 1, n - 1, arr, ans, 1);
			calc(i + 1, n - 1, arr, ans, -1);
			found = true;
			ll l_max = left(0, i - 1, arr, 1);
			ll l_min = left(0, i - 1, arr, -1);
			ll r_max = right(i + 1, n - 1, arr, 1);
			ll r_min = right(i + 1, n - 1, arr, -1);

			for (int j = 0; j <= (l_max + r_max); j++) {
				ans.insert(arr[i] + j);
			}
			for (int j = 0; j >= (l_min + r_min); j--) {
				ans.insert(arr[i] + j);
			}
		}
	}
	if (!found) {
		calc(0, n - 1, arr, ans, 1);
		calc(0, n - 1, arr, ans, -1);
	}
	cout << ans.size() << '\n';
	for (auto cur : ans) {
		cout << cur << ' ';
	}
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