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

ll n, m;

ll get_k(ll c, ll mx) {
	//mid * mid * mx
	ll up = 1e18 / c;

	ll low = 0, high = 1e9;
	ll ans = 0;
	while (low <= high) {
		ll mid = low + (high - low) / 2LL;
		if ((mid * mid) <= up && (mid * mid * c) <= mx) {
			ans = max(ans, mid);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return ans;
}


void get_cost(vector<ll> &arr, ll md, ll &cost, ll &items) {
	for (int i = 0; i < arr.size(); i++) {
		ll k = get_k(arr[i], md);
		cost += (k * k) * arr[i];
		if (cost >= m) {
			break;
		}
		items += k;
	}
}
 
void solve()
{
	cin >> n >> m;
	vector<ll> arr(n);
	cin >> arr;
	sort(arr.begin(), arr.end());
	ll low = 0, high = m, ans = 0;
	for (ll mid = 1; mid <= 1000; mid++) {
		// ll mid = low + (high - low) / 2LL;
		ll cost = 0, items = 0;
		get_cost(arr, mid, cost, items);
		if (cost <= m) {
			ans = max(ans, items);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
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