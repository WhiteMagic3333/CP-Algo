#ifndef ONLINE_JUDGE
#include "magic.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
typedef long long ll;
#define mod 1000000007

vector<ll> fac(1e6 + 1), inv_fac(1e6 + 1);

ll binpow(ll a, ll b, ll m) {
	a %= m;
	long long res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}


void pre()
{
	fac[0] = inv_fac[0] = 1;
	for (ll i = 1; i <= 1e6; i++)
	{
		fac[i] = (i * fac[i - 1]) % mod;
	}
	inv_fac[1e6] = binpow(fac[1e6], mod - 2, mod);
	for (ll i = 1e6; i > 1; i--)
	{
		inv_fac[i - 1] = (i * inv_fac[i]) % mod;
	}
}

ll nCr(ll a, ll b)
{
	return (((fac[a] * inv_fac[b]) % mod) * inv_fac[a - b]) % mod;
}

void solve()
{
	//Catalan number C(n) is the number of valid paranthsis of 2 * n brackets (n opened and n closed)
	//C(n) = nCr(2n, n) - nCr(2n, n + 1)
	ll n;
	cin >> n;
	if (n % 2)
		return void(cout << "0");
	n = n / 2;
	ll ans = (nCr(2 * n, n) - nCr(2 * n, n + 1) + mod) % mod;
	cout << ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	pre();
	solve();
	return 0;
}