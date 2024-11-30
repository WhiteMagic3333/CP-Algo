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

ll combination(ll a, ll b)
{
    return (((fac[a] * inv_fac[b]) % mod) * inv_fac[a - b]) % mod;
}

void solve()
{
	int n, x, p;
	cin >> n >> x >> p;
	ll smaller_req = 0, bigger_req = 0;
	ll low = 0, high = n;
	while(low < high)
	{
		ll mid = (low + high) / 2LL;
		if(mid == p)
		{
			low = mid + 1;
		}
		else if(mid < p)
		{
			low = mid + 1;
			smaller_req++;
		}
		else{
			high = mid;
			bigger_req++;
		}
	}
	if(smaller_req > x - 1 || bigger_req > n - x)
		return void(cout << "0");
	ll ans = (combination(x - 1, smaller_req) * fac[smaller_req]) % mod;
	ans = (ans * combination(n - x, bigger_req)) % mod;
	ans = (ans * fac[bigger_req]) % mod;
	ans = (ans * fac[n - smaller_req - bigger_req - 1]) % mod;
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