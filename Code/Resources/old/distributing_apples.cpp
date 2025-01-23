#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
 
vector<ll> fac(2e6 + 1), inv_fac(2e6 + 1);

ll binpow(ll a, ll b){
    ll res = 1;
    for(; b; b >>= 1){
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
    }
    return res;
}

void pre()
{
	fac[0] = inv_fac[0] = 1;
	for (ll i = 1; i <= 2e6; i++)
	{
		fac[i] = (i * fac[i - 1]) % mod;
		inv_fac[i] = (inv_fac[i - 1] * binpow(i, mod - 2)) % mod;
	}
}

ll fun(ll a, ll b)
{
	return (((fac[a] * inv_fac[b]) % mod) * inv_fac[a - b]) % mod;
}

void solve()
{
	ll n, m;
	cin >> n >> m;
	cout << fun(n + m - 1, n - 1);
}
 
int main()
{
 	pre();
	solve();
	return 0;
}