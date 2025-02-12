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



vector<ll> cur = {
	9,
	99,
	999,
	9999,
	99999,
	999999,
	9999999,
	99999999,
	999999999,
	9999999999,
	99999999999
};

bool check(ll cur) {
	while(cur) {
		int d = cur % 10;
		cur = cur / 10;
		if (d == 7) {
			return true;
		}
	}
	return false;
}

 
void solve()
{
	int ans = 10;
	ll n;
	cin >> n;
	for (auto c : cur) {
		for (int i = 0; i <= 10; i++) {
			if (check(n + i * c)) {
				ans = min(ans, i);
				break;
			}
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