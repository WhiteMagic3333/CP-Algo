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

long long int modInverse(long long int i){
    if(i==1) return 1;
    return (mod - ((mod/i)*modInverse(mod%i))%mod+mod)%mod;
}

ll ap_sum(ll l, ll r)
{
	l = l % mod;
	r = r % mod;
	ll l_sum = ((l * (l + 1) % mod) * modInverse(2LL)) % mod;
	ll r_sum = ((r * (r + 1) % mod) * modInverse(2LL)) % mod;
	ll cur = (r_sum - l_sum + mod) % mod;
	return cur;
}

void solve()
{
	ll n;
	cin >> n;
	if(n == 1)
		return void(cout << "1");
	ll ans = 0;
	ll div;
	for (ll i = 1; i * i <= n; i++)
	{
		ans = (ans + (n / i) * i) % mod;
		div = i;
	}
	div = n / div - 1;
	ll left = 0, right = 0, sum;
	for (ll i = div; i > 0; i--)
	{
		left = (n / (i + 1));
		right = (n / i);
		sum = ap_sum(left, right) % mod;
		sum = (sum * i) % mod;
		ans = (ans + sum) % mod;
		if(n / i == n)
			break;
	}
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}