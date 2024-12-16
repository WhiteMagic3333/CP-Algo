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

ll inside(ll x, ll y, ll n){
	ll ans = 1e18;
	ans = min({ans, n - x, n - y, x, y});
	return ans;
}

ll layer(ll x, ll y, ll n){
	x--;
	y--;
	ll levels = 0;
	ll num = n;
	while(num != 1){
		levels++;
		num = num >> 1;
	}
	ll inside_level = inside(x, y, n - 1LL);
	return levels - inside_level;
}
 
void solve()
{
	ll n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	ll l1 = layer(x1, y1, n);
	ll l2 = layer(x2, y2, n);
	cout << abs(l1 - l2);
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