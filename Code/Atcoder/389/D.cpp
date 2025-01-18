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

ll custom_sqrt(ll a) {
	ll low = 0, high = 1e9, ans = 0;
	while(low <= high) {
		ll mid = low + (high - low) / 2;
		if (mid * mid <= a) {
			ans = max(ans, mid);
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
	ll ans = 0;
	for (ll i = 1; i <= r; i++) {
		ans += custom_sqrt(r * r - i * i);
	}
	cout << 4 * ans;

}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}