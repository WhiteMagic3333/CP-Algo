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

ll summation(ll a) {
	return a * (a + 1LL) / 2;
}

bool is_in_range(ll a, ll b, ll i) {
	if (i >= a && i <= b)
		return true;
	return false;
}

void solve()
{
	ll n;
	cin >> n;
	/*these will store position of element i at index a[i] */
	vector<ll> a(n + 1), b(n + 1);
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		a[cur] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		int cur;
		cin >> cur;
		b[cur] = i + 1;
	}
	ll ans = 0;

	ll left = min(a[1], b[1]) - 1;
	ans += summation(left);

	ll right = n - max(a[1], b[1]);
	ans += summation(right);
	ll between = max(abs(a[1] - b[1]) - 1, 0LL);
	ans += summation(between);
	ll al, ar, bl, br;
	al = ar = a[1];
	bl = br = b[1];
	// for (ll cur = 1; cur <= n; cur++) {
	// 	al = min(al, a[cur]);
	// 	ar = max(ar, a[cur]);
	// 	bl = min(bl, b[cur]);
	// 	br = max(br, b[cur]);
	// 	if (cur != n ) {
	// 		if (is_in_range(al, ar, a[cur + 1]) || is_in_range(bl, br, b[cur + 1]))
	// 			continue;
	// 		ll left_prob = 0;
	// 		if (a[cur + 1] < al)
	// 			left_prob = a[cur + 1];
	// 		if (b[cur + 1] < bl)
	// 			left_prob = max(left_prob, b[cur + 1]);
	// 		ans += max(0LL, min(al, bl) - left_prob - 1);
	// 		ll right_prob = n;
	// 		if (a[cur + 1] > ar)
	// 			right_prob = a[cur + 1];
	// 		if (b[cur + 1] > br)
	// 			right_prob = min(right_prob, b[cur + 1]);
	// 		ans += max(0LL, right_prob - max(ar, br));
	// 	}
	// 	ans++;
	// 	break;
	// }
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}