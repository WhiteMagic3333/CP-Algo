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
	ll n, q;
	cin >> n >> q;
	vector<ll> p(n);
	cin >> p;
	sort(p.begin(), p.end());
	vector<ll> pre(n, 0);
	for (int i = 0; i < n; i++){
		pre[i] = p[i] + ((i != 0) ? pre[i - 1] : 0);
	}
	while(q--)
	{
		ll x, y;
		cin >> x >> y;
		ll ans = 0;
		ll prev = n - x - 1;
		ans += pre[prev + y];
		if(prev != -1)
			ans -= pre[prev];
		cout << ans << "\n";
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
 
	solve();
	return 0;
}