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
	ll n, x, k;
	cin >> n >> x >> k;
	string str;
	cin >> str;
	ll cpy = x, cpk = k, mn_x = abs(x);
	for (int i = 0; i < n; i++) {
		k--;
		if (str[i] == 'L') {
			x--;
		} else {
			x++;
		}
		mn_x = min(mn_x, abs(x));
		if (x == 0 || k == 0) {
			break;
		}
	}
	ll ans = 0;
	if (k == 0) {
		ans = (x == 0);
		return void(cout << ans);
	} else if (x != 0) {
		if ((x > 0 && cpy < x) || (x < 0 && cpy > x)) {
			return void(cout << "0");
		}

		ll change_per_n = abs(cpy) - abs(x);

		ll complete_cycles = abs(mn_x) / change_per_n;

		x = cpy;
		k = cpk;

		if ((abs(mn_x)) % change_per_n == 0) {
			complete_cycles--;
		}
		k -= complete_cycles * n;
		if (k <= 0) {
			return void(cout << "0");
		}
		if (x < 0) {
			change_per_n *= (-1);
		}
		x = x - (change_per_n * complete_cycles);
		for (int i = 0; i < n; i++) {
			k--;
			if (str[i] == 'L') {
				x--;
			} else {
				x++;
			}
			if (k == 0) {
				ans = (x == 0);
				return void(cout << ans);
			}
			if (x == 0) {
				ans++;
				break;
			}
		}
	}
	//x = 0, correct from here
	ans = 1;
	ll moves = 0;
	for (int i = 0; i < n; i++) {
		if (str[i] == 'L') {
			x--;
		} else {
			x++;
		}
		moves++;
		if (i + 1 == k) {
			ans += (x == 0);
			return void(cout << ans);
		}
		if (x == 0) {
			break;
		}
	}
	if (x != 0) {
		return void(cout << "1");
	}

	ans += k / moves;

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