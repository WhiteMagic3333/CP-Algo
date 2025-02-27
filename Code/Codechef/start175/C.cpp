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
	string str;
	cin >> str;
	int n = str.length();
	bool nice = true;
	int z = 0, o = 0;
	for (int i = 0; i < n; i++) {
		if (i > 0 && str[i] == str[i - 1]) {
			nice = false;
		}
		z += str[i] == '0';
		o += str[i] == '1';
	}
	if (nice) {
		return void(cout << "0");
	}
	int mn = min(z, o), mx = max(z, o), ans = 0;
	if (n % 2 == 0) {
		int diff = mx - mn;
		if (diff == 0) {
			ans = 1;
		} else if (diff == 2) {
			ans = 2;
		} else {
			ans = 3;
		}
	} else { //odd
		int diff = mx - mn;
		if (diff == 1) {
			ans = 1;
		} else if (diff == 3) {
			ans = 2;
		} else {
			ans = 3;
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