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

ll moves_to_zero(string &str) {
	ll x = 0, moves = 0;
	for (int i = 0; i < str.length(); i++) {
		moves++;
		if (str[i] == 'L') {
			x--;
		} else {
			x++;
		}
		if (x == 0) {
			return moves;
		}
	}
	return -1;
}
 
void solve()
{
	ll n, x, k;
	cin >> n >> x >> k;
	string str;
	cin >> str;
	ll before_zero = 0, ans = 0;
	ll mn_x = abs(x);
	ll old_x = x;
	for (int i = 0; i < n; i++) {
		before_zero++;
		if (str[i] == 'L') {
			x--;
		} else {
			x++;
		}
		mn_x = min(mn_x, abs(x));
		if (x == 0) {
			break;
		}
	}
	if (x != 0) {
		if ((x > 0 && old_x < x) || (x < 0 && old_x > x) || old_x == x) {
			return void(cout << "0");
		}
		ll change = abs(old_x) - abs(x);//converge
		ll times = abs(mn_x) / change;
		if (mn_x % change == 0) {
			times--;
		}
		x = old_x;
		before_zero = n * times;
		if (x > 0) {
			x -= times * change;
		} else {
			x += times * change;
		}
		for (int i = 0; i < n; i++) {
			before_zero++;
			if (str[i] == 'L') {
				x--;
			} else {
				x++;
			}
			if (x == 0) {
				break;
			}
		}
	}
	k = k - before_zero;
	if (k < 0) {
		return void(cout << "0");
	}
	ans = 1;
	ll mv = moves_to_zero(str);
	if (mv != -1) {
		ans += k / mv;
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