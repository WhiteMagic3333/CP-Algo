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

long long int modInverse(long long int i, long long int md) {
	if (i == 1) return 1;
	return (md - ((md / i) * modInverse(md % i, md)) % md + md) % md;
}

long long binpow(long long a, long long b, long long m) {
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

struct data {
	ll x;
	ll k;
};

ll numberOfDivisors(vector<data> &arr)
{
	ll ans = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		ans = (ans * (arr[i].k + 1)) % mod;
	}
	return ans;
}

ll sumOfDivisors(vector<data> &arr)
{
	ll ans = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		ll cur = (binpow(arr[i].x, arr[i].k + 1, mod) - 1 + mod) % mod;
		cur = (cur * modInverse((arr[i].x - 1 + mod) % mod, mod)) % mod;
		ans = (ans * cur) % mod;
	}
	return ans;
}

ll productOfDivisors(vector<data> &arr)
{
	ll n = 1;
	ll nod = 1;
	bool flag = true;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr[i].k % 2 == 1 && flag) {
			nod = (nod * ((arr[i].k + 1) / 2LL)) % (mod - 1);
			flag = false;
		}
		else
			nod = (nod * (arr[i].k + 1)) % (mod - 1);
	}
	if (flag)
	{
		for (int i = 0; i < arr.size(); i++)
		{
			arr[i].k = arr[i].k / 2;
		}
	}
	for (int i = 0; i < arr.size(); i++)
	{
		n = (n * binpow(arr[i].x, arr[i].k, mod)) % mod;
	}
	ll ans = binpow(n, nod, mod );
	return ans;
}


void solve()
{
	int n, x, k;
	cin >> n;
	vector<data> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].k;
	ll a = numberOfDivisors(arr);
	ll b = sumOfDivisors(arr);
	ll c = productOfDivisors(arr);
	cout << a << " " << b << " " << c;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	solve();
	return 0;
}