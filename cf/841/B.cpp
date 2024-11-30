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

ll sum(ll n)
{
	ll ans = n * (n + 1LL);
	ans = ans / 2LL;
	ans = ans % mod;
	return ans;
}

ll sq_sum(ll n)
{
	ll ans = n * (n + 1LL);
	ans = ans / 2LL;
	bool div = false;
	if(ans % 3 == 0){
		ans = ans / 3;
		div = true;
	}
	ans = ans % mod;
	ll other = 2 * n + 1;
	if(div == false)
		other = other / 3;
	other = other % mod;
	ans = (ans * other) % mod;
	return ans;
}

void solve()
{
	ll n;
	cin >> n;
	ll ans = sq_sum(n);
	ans = (ans + sq_sum(n - 1)) % mod;
	ans = (ans + sum(n - 1)) % mod;
	ans = (ans * 2022L) % mod;
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