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

vector<vector<double>> dxy = {
	{0.5, 0.5},
	{-0.5, 0.5},
	{0.5, -0.5},
	{-0.5, -0.5},
};

bool valid(ll x, ll y, double r) {
	for (auto d : dxy) {
		double dx = x + d[0];
		double dy = y + d[1];
		double d2 = dx * dx + dy * dy;
		if (d2 > (r * r)) {
			return false;
		}
	}
	return true;
}

ll get_squares (ll r, ll i) {
	ll ans = 0;
	ll low = 0, high = r;
	//point will be mid, i
	while (low <= high) {
		ll mid = low + (high - low) / 2LL;
		if (valid(mid, i, r)) {
			ans = max(mid, ans);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return ans;
}
 
void solve()
{
	ll r;
	cin >> r;
	ll ans = (r - 1) * 4 + 1;
	ll sq_in_qd = 0;
	for (ll i = 1; i < r; i++) {
		sq_in_qd += get_squares(r, i);
	}
	ans += sq_in_qd * 4;
	cout << ans;
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}